#include<iostream>
#include<cstdio>
#include<cmath>
typedef long long int ll;
using namespace std;
#define mx 1000000
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
}
int main()
{
    sive();
    ll n;
    while(cin>>n)
    {
        if(n==0)
            return 0;
        ll  cn=0;
        for(int i=1; i<=n; i++)
        {
            if(isprime[i]==false)
            {
                if(n%i==0)
                    cn++;
            }
        }
        cout<<n<<" : "<<cn<<endl;
    }
}

