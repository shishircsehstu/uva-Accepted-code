#include<iostream>
#include<cstdio>
typedef long long ll;
using namespace std;
int main()
{
    ll n,k,n1,n2,n3,i=1;
    while(cin>>n)
    {
        printf("%4lld.",i++);
        if(n==0)
            cout<<" 0";
        n1=n/10000000;
        n2=n%10000000;
        if(n1>0)
        {
            n=n1/10000000;
            if(n>0)
            {
                cout<<" "<<n<<" kuti";
            }
            n1=n1%10000000;
            n=n1/100000;
            if(n>0)
            {
                cout<<" "<<n<<" lakh";
            }
            n1=n1%100000;
            n=n1/1000;
            if(n>0)
            {
                cout<<" "<<n<<" hajar";
            }
            n1=n1%1000;
            n=n1/100;
            if(n>0)
            {
                cout<<" "<<n<<" shata";
            }
            n1=n1%100;
            if(n1>0)
                cout<<" "<<n1;
            cout<<" kuti";
        }
        n1=n2/10000000;
        if(n1>0)
        {
            cout<<" "<<n1<<" kuti";
        }
        n2=n2%10000000;
        n1=n2/100000;
        if(n1>0)
        {
            cout<<" "<<n1<<" lakh";
        }
        n2=n2%100000;
        n1=n2/1000;
        if(n1>0)
        {
            cout<<" "<<n1<<" hajar";
        }
        n2=n2%1000;
        n1=n2/100;
        if(n1>0)
        {
            cout<<" "<<n1<<" shata";
        }
        n2=n2%100;
        if(n2>0)
            cout<<" "<<n2;
        cout<<endl;
    }
}

