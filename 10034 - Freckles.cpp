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
vector<int>adj[100];
map< string,vector<string> > G;
double xx[1001],yy[1001];
map<string,vector<double> > cost;
map<string,int>visited;
class graph
{
public:
    string u;
    double v;                    /* u=node number, v=weight */
    graph()
    {

    }
    graph(string a, double b)
    {
        u=a;
        v=b;
    }
};
bool operator<(graph A, graph B)
{
    return B.v<A.v;
}
int main()
{
    int node1,node2,i,j,w,n,m,t,ck,count;
    string s1,s2,s3,s4;
    priority_queue<graph>PQ;
    char str[100];
    double x,y,x2,y2,cst,ans;
    ck=0;
    scanf("%d",&t);
    while(t--)
    {
        if(ck==1)
            printf("\n");
        scanf("%d",&m);
        visited.clear();
        for(i=1; i<=m; i++)
        {
            scanf("%lf%lf",&x,&y);
            xx[i]=x;
            yy[i]=y;
        }
        for(i=1; i<m; i++)
        {
            x=xx[i];
            sprintf(str,"%lf",x);
            s1=str;
            y=yy[i];
            sprintf(str,"%lf",y);
            s2=str;
            for(j=i+1; j<=m; j++)
            {
                x2=xx[j];
                y2=yy[j];
                cst=sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
                sprintf(str,"%lf",x2);
                s3=str;
                sprintf(str,"%lf",y2);
                s4=str;
                G[s1+s2].push_back(s3+s4);
                G[s3+s4].push_back(s1+s2);
                cost[s1+s2].pb(cst);
                cost[s3+s4].pb(cst);
            }
        }
        count=0;
        ans=0;
        PQ.push(graph(s1+s2,0));
        string u;
        graph top;
        while(true)
        {
            top=PQ.top();
            PQ.pop();
            u=top.u;
            if(visited[u]==0)
            {
                for(i=0; i<G[u].size(); i++)
                {
                    PQ.push(graph(G[u][i],cost[u][i]));
                }
                visited[u]=1;
                count++;
                ans+=top.v;
                if(count==m)
                    break;
            }
        }
        while(!PQ.empty())
            PQ.pop();
        for(i=1; i<=m; i++)
        {
            x=xx[i];
            y=yy[i];
            sprintf(str,"%lf",x);
            s1=str;
            sprintf(str,"%lf",y);
            s2=str;
            G[s1+s2].clear();
            cost[s1+s2].clear();
        }
        printf("%.2lf\n",ans);
        ck=1;
    }
    return 0;
}


