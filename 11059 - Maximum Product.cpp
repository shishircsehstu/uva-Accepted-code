#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstdio>
#include<cctype>
#define sc scanf
#define pf printf
#include<cstring>
#include<algorithm>
using namespace std;
vector<char>ch;
typedef long long li;
vector<li>v;
int ar[100];
int main()
{
    int n,i,j,k,ck,s,x,siz,s1,s2,t=1;
    double sum1,sum2;
    while(sc("%d",&n)==1)
    {
        sum2=0;
        for(i=0; i<n; i++)
            sc("%d",&ar[i]);
        for(i=0; i<n; i++)
        {
            sum1=1;
            for(j=i; j<n; j++)
            {
                sum1*=ar[j];
                if(sum1>sum2)
                    sum2=sum1;
            }
        }
        pf("Case #%d: The maximum product is %.0lf.\n\n",t++,sum2);
    }
}

