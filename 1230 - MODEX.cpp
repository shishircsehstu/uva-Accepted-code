#include<bits/stdc++.h>
using namespace std;
long long  ar[1000],r;
#define ll long long
void bi_nary(long long  n)
{
    while(n>0)
    {
        ar[r++]=n%2;
        n/=2;
    }
    //for(int i=r-1; i>=0; i--)
    //   cout<<ar[i];
    // cout<<endl;
}
int big_mod(ll base,ll pow,ll mod)
{
    int ans,p;
    bi_nary(pow);
    ans=1;
    p=base%mod;
    for(long long  i=0; i<r; i++)
    {
        if(ar[i]==1)
            ans=(ans*p)%mod;
        p=(p*p)%mod;
    }
    r=0;
    return ans;
}
int  main()
{
    long long  base,pow,mod,p,ans,t;
    while(scanf("%lld",&t)==1)
    {
        if(t==0)  break;
        while(t--)
        {
            scanf("%lld %lld %lld",&base,&pow,&mod);
            cout<<big_mod(base,pow,mod)<<endl;
        }
    }
}
