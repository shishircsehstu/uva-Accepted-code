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

#define P(a) prlong longf("%d\n",a)
#define PLN(a) prlong longf("%I64d ",a)
#define pf prlong longf

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl

#define pii pair<long long,long long>
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;
//long long dx[]= {-1,-1,0,0,1,1};
//long long dy[]= {-1,0,-1,1,0,1};
//long long dx[]= {0,0,1,-1};/*4 side move*/
//long long dy[]= {-1,1,0,0};/*4 side move*/
//long long dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//long long dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//long long dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//long long dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
map<ll,bool>visi;
#define siz1 100001
bool vis1[siz1],vis2[siz1];
long long ar[siz1];
long long r;
long long rem1(long long base,long long pow,long long mod)
{
    long long  ans=1;
    long long  p=base%mod;
    ans=(ans*p)%mod;
    p=(p*p)%mod;
    return ans;
}
int  main()
{
    //freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    long long i,j,n,m,a,c,b,ck,t,x,y,ans,rem,cnt,lo,hi,sum,cs=1;
    while(scanf("%lld",&n)==1)
    {
        a=1;
        cnt=1;
        while(1)
        {
            a=rem1(a,1,n);
            if(a==0)
            {
                printf("%lld\n",cnt);
                break;
            }
            a=a*10+1;
            cnt++;
        }
    }
}
/*
yes
no
yes
*/


