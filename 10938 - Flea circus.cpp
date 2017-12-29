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

#define P(a) printf("%d\n",a)
#define PLN(a) printf("%I64d ",a)
#define pf printf

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl
#define pb push_back
#define pii pair<int,int>
#define mk make_pair
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
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65, 'a'=97 '0'=48


map<ll,bool>visi;
int ar[siz];
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
#define mx 100002
int L[mx];
int sparse_t[mx][22];
int T[mx];
vector<int>g[mx];
//Complexity: O(NlgN,lgN)
void dfs(int from,int u,int dep)
{
    T[u]=from;   ///T store parent of child
    L[u]=dep;    /// L store level of node
    for(int i=0; i<(int)g[u].size(); i++)
    {
        int v=g[u][i];
        if(v==from) continue;
        dfs(u,v,dep+1);
    }
}

int lca_query(int N, int p, int q)
{
    int tmp, log, i;

    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;

    log=1;
    while(1)
    {
        int next=log+1;
        if((1<<next)>L[p])break;
        log++;
    }
    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = sparse_t[p][i];

    if (p == q)
        return p;

    for (i = log; i >= 0; i--)
        if (sparse_t[p][i] != -1 && sparse_t[p][i] != sparse_t[q][i])
            p = sparse_t[p][i], q = sparse_t[q][i];

    return T[p];
}

void lca_init(int N)
{
    memset (sparse_t,-1,sizeof(sparse_t));

    int i, j;
    for (i = 0; i < N; i++)
        sparse_t[i][0] = T[i];

    for (j = 1; 1 << j < N; j++)
    {
        for (i = 0; i < N; i++)
        {
            if (sparse_t[i][j - 1] != -1)
            {
                sparse_t[i][j] = sparse_t[sparse_t[i][j - 1]][j - 1];
            }
        }
    }

}
int main(void)
{

    //freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
    int i,j,n,k,sum,x,y,qu,lca,lnthx,lnthy,par,yy,lol,par2;

    while(si(n)==1)
    {
        if(n==0) break;
        for(i=1; i<n; i++)
        {
            si(x),si(y);
            x--,y--;
            g[x].pb(y);
            g[y].pb(x);
        }
        dfs(0, 0, 0);
        lca_init(n);
        /*
        for(i=0;i<n;i++)
        {
            for(j=0;j<=log2(n);j++)
            {
                cout<<sparse_t[i][j]+1<<" ";
            }
            cout<<endl;
        }
        */
        //cout<<endl;
        si(qu);
        while(qu--)
        {
            si(x),si(y);
            x--,y--;
            lca=lca_query(n,x,y);
            lnthx=L[x]-L[lca];
            lnthy=L[y]-L[lca];
            if(lnthx==lnthy)
            {
                printf("The fleas meet at %d.\n",lca+1);
                continue;
            }
            sum=lnthx+lnthy;
            if(lnthx>lnthy) yy=x;
            else yy=y;
            if(sum%2==0)
            {
                sum/=2;
                while(sum)
                {
                    lol=log2(sum);
                    par=sparse_t[yy][lol];
                    sum-=ceil(pow(2,lol));
                    yy=par;
                }
                printf("The fleas meet at %d.\n",par+1);
            }
            else
            {
                sum/=2;
                //cout<<sum<<" --"<<yy+1<<endl;
                int sum2=sum+1;
                int yy2=yy;
                if(sum==0) par=yy;
                while(sum)
                {
                    lol=log2(sum);
                    // cout<<lol<<endl;
                    par=sparse_t[yy][lol];
                    sum-=ceil(pow(2,lol));
                    yy=par;

                }
                while(sum2)
                {
                    lol=log2(sum2);
                    //cout<<"lol2="<<lol<<endl;
                    par2=sparse_t[yy2][lol];
                    sum2-=ceil(pow(2,lol));
                    yy2=par2;
                }
                if(par<par2)
                    swap(par,par2);
                printf("The fleas jump forever between %d and %d.\n",par2+1,par+1);
            }
        }
        for(i=0; i<=n; i++) g[i].clear();
    }

    return 0;
}
/*
13
1 2
1 3
2 4
2 5
3 6
3 7
5 8
8 9
9 10
10 11
11 12
12 13

6
4 5
4 1
1 3
5 2
3 6
10
1 5
2 2
2 5
3 5
3 6
4 4
4 5
4 6
5 5
6 6

The fleas meet at 4.
The fleas meet at 2.
The fleas jump forever between 2 and 5.
The fleas jump forever between 1 and 4.
The fleas jump forever between 3 and 6.
The fleas meet at 4.
The fleas jump forever between 4 and 5.
The fleas jump forever between 1 and 3.
The fleas meet at 5.
The fleas meet at 6.

8
1 2
1 3
2 4
2 5
3 6
3 7
5 8
5
5 1
7 4
1 8
4 7
7 8

*/


