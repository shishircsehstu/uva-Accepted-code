//BISMILLAHIR RAHMANIR RAHIM
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

#define pf printf
#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define sc scanf
#define sc1(a) cin>>a
#define sc2(a,b) cin>>a>>b
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl
#define endl '\n'
#define pii pair(ll ,ll )
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180);
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;
#define mx 100002
vector<ll >g[mx];
vector<ll >cost[mx];
ll  ar1[mx];
vector<int>vec2;
ll  r1=0;
int vis[siz];
struct node
{
    ll  u,w;
    node(ll  a,ll  b)
    {
        u=a;
        w=b;
    }
    bool operator < (const node& p) const
    {
        return p.w < w;
    }
};
ll  d[mx],par[mx];
ll  dijkstra(int src,ll  n)
{
    memset(par,-1,sizeof(par));
    memset(d,63,sizeof(d));
    priority_queue<node>q;
    q.push(node(src,0));
    d[src]=0;
    vis[src]=1;
    while(!q.empty())
    {
        node top=q.top();
        q.pop();
        ll  u=top.u;
        if(top.u==n)
        {
            return d[n];
        }
        // cout<<top.u<<"  "<<top.w<<endl;
        for(ll  i=0; i<g[u].size(); i++)
        {
            ll  v=g[u][i];
            if(max(d[u],cost[u][i])<d[v])
            {
                d[v]=max(d[u],cost[u][i]);
                //cout<<"cost "<<d[v]<<endl;
                q.push(node(v,d[v]));
            }
        }
    }
    return -1;
}
int  main()
{
    //memset(d,63,sizeof(d));
    //cout<<d[0]<<endl;
    ll  k,n,e,i,ret,t,ck=0,cs=1;
    while(sc("%lld%lld%lld",&n,&e,&k)==3)
    {
        if(n==0&&e==0&&k==0) break;
        if(ck==1) printf("\n");
        for( i=0; i<e; i++)
        {
            ll  u,v,w;
            sc("%lld%lld%lld",&u,&v,&w);
            g[u].push_back(v);
            g[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        int src,dis,x,y;
        printf("Case #%lld\n",cs++);
        for(i=0; i<k; i++)
        {
            scanf("%d%d",&x,&y);
            ll k=dijkstra(x,y);
            if(k==-1)
                printf("no path\n");
            else
                printf("%lld\n",k);
        }
        for(i=1; i<=1000; i++)
            g[i].clear(),cost[i].clear();
        ck=1;
    }

}


