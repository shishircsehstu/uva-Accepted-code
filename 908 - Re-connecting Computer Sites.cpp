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

#define sc scanf
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%I64d",&t)
#define sii(a,b) scanf("%d%d",&a,&b)
#define pb push_back

#define P(a) printf("%d\n",a)
#define PLN(a) printf("%I64d ",a)
#define pf printf

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl

#define pii pair<int,int>
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 1000001
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
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
map<ll,bool>visi;
vector<int>adj[1000001],cost[1000001];
int visited[1000002],parent[10001];
class graph
{
public:
    int u,v;                    /* u=node number, v=weight */
    graph()
    {

    }
    graph(int a, int b)
    {
        u=a;
        v=b;
    }
};
bool operator<(graph A, graph B)
{
    return B.v<A.v;
}
int prims(int n)
{
    int i,u,ans,count=0;
    ans=0;
    priority_queue<graph>PQ;
    while(!PQ.empty())
        PQ.pop();
    PQ.push(graph(1,0));
    graph top;
    while(true)
    {
        top=PQ.top();
        PQ.pop();
        u=top.u;
        if(visited[u]==0)
        {
            for(i=0; i<adj[u].size(); i++)
            {
                //    cout<<adj[u][i]<<endl;
                PQ.push(graph(adj[u][i],cost[u][i]));
            }
            visited[u]=1;
            count++;
            ans+=top.v;
            if(count==n)
                break;
        }
    }
    return ans;
}
int main()
{
    int k,i,j,u,v,w,n,m,count,ans1,ans2,ck;
    ck=0;
    while(cin>>n)
    {
        if(ck==1)
            printf("\n");
        ans1=0;
        mem(visited);
        for(i=1; i<n; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            ans1+=w;
        }
        scanf("%d",&k);
        for(i=1; i<=k; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            adj[u].pb(v);
            adj[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
        }
        scanf("%d",&k);
        for(i=1; i<=k; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            adj[u].pb(v);
            adj[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
        }
        ans2=prims(n);
        printf("%d\n%d\n",ans1,ans2);
        for(i=1; i<=n; i++)
        {
            adj[i].clear();
            cost[i].clear();
        }
        ck=1;
    }
    return 0;
}


