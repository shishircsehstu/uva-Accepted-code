#include<iostream>
#include<cstdio>
#include<cmath>
typedef long long int ll;
using namespace std;
#define mx 20000000
ll r=1;
int ar[mx];
bool isprime[mx];
void sive()
{
    ll i,sqt,j,y;
    for(i=4; i<=mx; i+=2)
        isprime[i]=true;
    isprime[0]=isprime[1]=true;
    sqt=sqrt(mx);
    for(i=3; i<= sqt; i+=2)
    {
        for(j=2*i; j<=mx; j+=i)
            isprime[j]=true;
    }
    for(i=3; i<=mx; i++)
    {
        if(!isprime[i])
        {
            y=2+i;
            if(!isprime[y])
                ar[r++]=i;
        }
    }
}
int main()
{
    sive();
    ll n;
    while(cin>>n)
    {
        printf("%c",'(');
        cout<<ar[n]<<", "<<ar[n]+2;
        printf("%c\n",')');
    }
}
