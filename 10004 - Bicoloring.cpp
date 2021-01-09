/*
    Md. Saddam Hossain shishir
    shishir.cse.hstu@gmail.com
    uva 10004
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

int n, e;
int colored[MAX], visited[MAX];
vector< int > G[MAX];

bool is_bicoloredte()
{
    int i, u, v, start;
    queue< int > Q;
    start = 0; // nodes labeled from 0
    Q.push(start);
    colored[start] = 1; // 1 left, 2 right
    visited[start] = 1;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for(i=0; i < G[u].size(); i++)
        {
            v = G[u][i];
            if(colored[u] == colored[v]) return false;
            if(visited[v] == 0)
            {
                visited[v] = 1;

                if(colored[u]==1)
                    colored[v] = 2;
                else
                    colored[v] = 1;
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
        if(is_bicoloredte()) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
        memset(colored,0,sizeof colored);
        memset(visited,0,sizeof visited);
        for(i=0; i<=n; i++)
            G[i].clear();
    }
    return 0;
}

