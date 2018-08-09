/******************************************************************
 *                   BISMILLAHIR RAHMANIR RAHIM                   *
 *                     Saddam Hossain shishir                     *
 *       Hajee Mohammad Danesh Science & Technology University    *
 *                                                                *
 ***************************************************************** */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<set>
#include<cmath>
#include<cctype>
#include<stack>
#include<cstdlib>
#include<utility>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
#include<limits>
#include<limits.h>

#define all(v) v.begin(),v.end()

#define sc scanf
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%I64d",&t)

#define sii(a,b) scanf("%d%d",&a,&b)

#define P(a) printf("%d\n",a)
#define PLN(a) printf("%I64d ",a)
#define pf printf

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second

#define pb push_back
#define pii pair<int,int>
#define mk make_pair
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 5002
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48


//upper bound and lower bound

#define LB(a,value) (lower_bound(all(a),value)-a.begin())
#define UB(a,value) (upper_bound(all(a),value)-a.begin())
//S.insert(lower_bound(S.begin( ),S.end( ),x),x); //S is vector

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

struct edge
{
    int to,w;
    edge() {}
    edge(int a, int b)
    {
        to=a;
        w=b;
    }
};

struct el
{
    int vertex,cost;
    el() {}
    el(int a,int b)
    {
        vertex=a;
        cost=b;
    }
    bool operator<(const el &a) const
    {
        return cost>a.cost;
    }
};

priority_queue <el> pq;
vector <edge> v[siz];
vector <int> dist[siz];
void Dijkstra(int starting_node, int ending_node)
{
    int i,current_distance;
    el curr;
    for(i=0; i<=200; i++)
        dist[i].clear();
    pq.push(el(starting_node,0));
    while(!pq.empty())
    {

        curr=pq.top();
        // cout<<"Yes\n";
        pq.pop();
        if(dist[curr.vertex].size()==0)
            dist[curr.vertex].push_back(curr.cost);

        else if(dist[curr.vertex].back()!=curr.cost)

            dist[curr.vertex].push_back(curr.cost);

        if(dist[curr.vertex].size()>2)// kth shortest path k=2
            continue;
        for(i=0; i<v[curr.vertex].size(); i++)
        {
            // cout<<"YES2\n";
            current_distance=v[curr.vertex][i].w+curr.cost;
            pq.push(el(v[curr.vertex][i].to,current_distance));
        }
    }
    // printf("%lld\n", dist[ending_node][1]);
}
int vis[siz];
vector<int>graph[siz];
void bfs(int x,int y)
{
    mem(vis);
    queue<int>qq;
    qq.push(x);
    vis[x]=1;
    while(!qq.empty())
    {
        int i,u=qq.front();
        qq.pop();
        for(i=0; i<graph[u].size(); i++)
        {
            int v=graph[u][i];
            if(vis[v]==0)
            {
                vis[v]=1;
                qq.push(v);
            }
        }
    }
}
int  main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int i,a,b,c,n,m,t,x,y,cs=1;
    while(scanf("%d %d",&n,&m)==2)
    {
        for(i=0; i<=200; i++)
            v[i].clear(),graph[i].clear();
        for(i=1; i<=m; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            graph[a].pb(b);
            graph[b].pb(a);
            v[a].push_back(edge(b,c));
            v[b].push_back(edge(a,c));
        }
        printf("Set #%d\n",cs++);
        scanf("%d",&a);
        for(i=0; i<a; i++)
        {
            scanf("%d%d",&x,&y);
            Dijkstra(x,y);
            if(dist[y].size()==0)
                printf("?\n");
            else
                printf("%d\n",dist[y][1]);

        }
    }
}
/*
3 3
1 2 100
1 3 50
2 3 200

4 4
1 2 5
1 3 1
2 3 7
3 4 1

*/

