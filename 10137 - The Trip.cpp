#include<iostream>
#include<cstdio>
#include<cmath>
#define mx 10001
typedef long long ll;
using namespace std;
double ar[mx];
int main()
{
    ll i,j,n;
    double sum,av,dif,resp,resn,d;
    while(cin>>n)
    {
        if(n==0)
            return 0;
        resp=resn=sum=0;
        for(i=0; i<n; i++)
        {
            cin>>ar[i];
            sum+=ar[i];
        }
        av=sum/n;
        for(i=0; i<n; i++)
        {
            dif=double(ll((ar[i]-av)*100))/100;
            if(dif>0)
                resp+=dif;
            else
                resn+=-1*dif;
        }
        if(resp>resn)
            d=resp;
        else
            d=resn;
        if(d<0)
            d=-d;
        printf("$%.2lf\n",d);
    }
}

