#include <cstdio>
#include<iostream>
#include <vector>
#include <queue>
#include<cstring>
using namespace std;
#define MAX 1001

int n, e;
int partition[MAX], visited[MAX];
vector< int > G[MAX];

bool is_bipartite()
{
    int i, u, v, start;
    queue< int > Q;
    start = 0; // nodes labeled from 0
    Q.push(start);
    partition[start] = 1; // 1 left, 2 right
    visited[start] = 1;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for(i=0; i < G[u].size(); i++)
        {
            v = G[u][i];
            if(partition[u] == partition[v]) return false;
            if(visited[v] == 0)
            {
                visited[v] = 1;
                partition[v] = 3 - partition[u]; // alter 1 and 2
                Q.push(v);
            }
        }
    }
    return true;
}

int main()
{
    int i, u, v;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        scanf("%d",&e);
        for(i = 0; i < e; i++)
        {
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(is_bipartite()) printf("Yes Bipartit.\n");
        else printf("NOT Bipartit.\n");
        memset(partition,0,sizeof partition);
        memset(visited,0,sizeof visited);
        for(i=0; i<=n; i++)
            G[i].clear();
    }
    return 0;
}

