#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long int ll;
#define M 2000001
int phi[M];
int ar[M];
void ca()
{
    for (int i = 1; i < M; i++)
    {
        phi[i] = i;
    }
    for (int p = 2; p < M; p++)
    {
        if (phi[p] == p)
        {
            for (int k = p; k < M; k += p)
            {
                phi[k] -= phi[k] / p;
            }
        }
    }
}
void cnt()
{
    ll i,j,k=0;
    for(i=1; i<=M; i++)
    {
        j=i;
        while(phi[j]>1)
        {
            k++;
            j=phi[j];
        }
        k++;
        ar[i]=k;
    }
}
int main()
{
    ca();
    cnt();
    ll n,m,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        cout<<ar[m]-ar[n-1]<<endl;
    }
}
