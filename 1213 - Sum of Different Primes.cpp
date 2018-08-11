//BISMILLAHIR RAHMANIR RAHIM
#include<iostream>
#include<list>
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
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*
map<int,int>mp;
#define MX 1000
int coin[200];
long long dp[190][1121][15];
#define mx 11200
bool isprime[mx+5];
int cn,num_coin;
void sive()
{
    ll i,sqt,j;
    for(i=4; i<=mx; i+=2)
        isprime[i]=true;
    isprime[0]=isprime[1]=true;
    sqt=sqrt(mx);
    for(i=3; i<= sqt; i+=2)
    {
        if(isprime[i]==false)
        {
            for(j=2*i; j<=mx; j+=i)
                isprime[j]=true;
        }
    }

}
long long call(int n,int i,int amount)
{
    if(n==cn||i>=num_coin)
    {
        if(n==cn)
        {
            if(amount==0)
                return 1;
            else return 0;
        }
        return 0;
    }
    if(dp[i][amount][n]!=-1) return dp[i][amount][n];
    long long ret1=0,ret2=0;
    if(amount-coin[i]>=0) ret1=call(n+1,i+1,amount-coin[i]);
    ret2=call(n,i+1,amount);
    return dp[i][amount][n]=ret1+ret2;
}
int main()
{
    sive();
    int i,num,r;
    while(scanf("%d%d",&num,&cn)==2)
    {
        if(num==0&&cn==0)
            break;
        r=0;
        for(i=1; i<=num; i++)
        {
            if(isprime[i]==false)
                coin[r++]=i;
        }
        num_coin=r;
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",call(0,0,num));
    }
    return 0;
}
/*
int fun(int i,int num,int tkn)
 {
 if(num==0 and tkn==x)
 return 1;
 if(num<0 or i>187 or num-prm[i]<0 or tkn>x)
 return 0;
 if((num==0 and tkn!=x)or(num!=0 and tkn==x))
 return 0;
 if(mm[i][num][tkn]!=-1)
 return mm[i][num][tkn];
 return mm[i][num][tkn]=fun(i+1,num,tkn)+fun(i+1,num-prm[i],tkn+1);
 }
*/

