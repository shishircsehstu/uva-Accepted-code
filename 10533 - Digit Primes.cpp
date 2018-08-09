#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
typedef long long int ll;
#define mx 1000001
using namespace std;
bool ar[mx];
ll ar2[mx];
void sive()
{
    ll i,j,sq;
    for(i=4; i<=mx; i+=2)
        ar[i]=true;
    ar[0]=ar[1]=true;
    ar[2]=0;
    sq=sqrt(mx);
    for(i=3; i<=sq; i+=2)
    {
        for(j=2*i; j<=mx; j+=i)
            ar[j]=true;
    }
}
int di(ll n)
{
    ll sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
void  digit()
{
    ll i,j,k=1;
    ar2[2]=1;
    for( i=3; i<=1000000; i+=2)
    {
        j=i;
        ll sum=0;
        if(ar[j]==false&&ar[di(i)]==false)
        {
            k++;
        }
        ar2[i]=ar2[i+1]=k;
    }
}
int main()
{
    sive();
    digit();
    ll lo,hi,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&lo,&hi);
        printf("%lld\n",ar2[hi]-ar2[lo-1]);
    }
}
