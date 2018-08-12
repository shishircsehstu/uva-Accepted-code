#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
typedef long long ll;
using namespace std;
int main()
{
    ll num1,num2,i,j,b,d,k;
    string n,n1,n2,n3;
    while(cin>>n1)
    {
        n=n1;
        k=0;
        sort(n.begin(),n.end());
        n3=n;
        if(n[0]=='0')
        {
            for(i=0; i<n.size(); i++)
            {
                if(n[i]=='0')
                    k++;
            }
            n2=n[k];
            for(i=0; i<k; i++)
                n2+='0';
            for(i=k+1; i<n.size(); i++)
                n2+=n[i];
            n=n2;
            reverse(n3.begin(),n3.end());
            num1=atoll(n3.c_str());
            num2=atoll(n2.c_str());
            if(num1>num2)
                swap(num2,num1);
            b=num2-num1;
            d=b/9;
            cout<<num2<<" - "<<num1<<" = "<<b<<" = "<<9<<" * "<<d<<endl;
        }
        else
        {
            reverse(n.begin(),n.end());
            num1=atoll(n.c_str());
            num2=atoll(n3.c_str());
            if(num1>num2)
                swap(num2,num1);
            b=num2-num1;
            d=b/9;
            cout<<num2<<" - "<<num1<<" = "<<b<<" = "<<9<<" * "<<d<<endl;
        }
    }
}
