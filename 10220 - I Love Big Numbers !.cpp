#include<iostream>
#include<cstdio>
#define mx 10000
using namespace std;
typedef long long int ll;
ll ar1[mx];
ll ar2[mx],r1,r;
void mul(ll k)
{
    ll i,j,sum,hnd=0;
    for(i=0; i<r; i++)
    {
        sum=ar1[i]*k+hnd;
        if(i==r-1)
        {
            while(sum>0)
            {
                ar2[r1++]=sum%10;
                sum/=10;
            }
        }
        else
        {
            ar2[r1++]=sum%10;
            hnd=sum/10;
        }
    }
    for(i=0; i<r1; i++)
    {
        ar1[i]=ar2[i];
    }
    r=r1;
    r1=0;
}
int main()
{
    ll n,k,j,sum,i,n1,hnd,s;
    while(cin>>n)
    {
        sum=0;
        if(n==0)cout<<1;
        else if(n==1)cout<<1;
        else if(n==2)cout<<2;
        else
        {
            n1=n;
            while(n>0)
            {
                ar1[r++]=n%10;
                n/=10;
            }
            for(k=n1-1; k>=2; k--)
                mul(k);
            for(i=r-1; i>=0; i--)
                sum+=ar2[i];
                cout<<sum;
        }
        cout<<endl;
        r1=r=0;
    }
}

