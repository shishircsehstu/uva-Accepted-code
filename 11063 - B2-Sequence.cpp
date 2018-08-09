#include<iostream>
#include<cstdio>
#include<set>
#define mx 100001
typedef long long int li;
using namespace std;
int  ar[mx];
int n, ar1[mx];
int  cal()
{
    set<int >s;
    if(ar[0]<1)
        return 0;
    for(int i=0; i<n-1; i++)
    {
        if(ar[i]>=ar[i+1])
            return 0;
    }
    for(int  i = 0 ; i < n ; i++)
    {
        for(  int j = i ; j < n ; j++)
        {
            if(s.count(ar[i]+ar[j])) return 0;
            s.insert(ar[i]+ar[j]);
        }
    }
    return 1;
}
int main()
{
    int  i,j,k,a,r,ck,sum,cs=1;
    while(cin>>n)
    {
        ck=1;
        for(i=0; i<n; i++)
            cin>>ar[i];
        ck=cal();
        if(ck==1)
            printf("Case #%d: It is a B2-Sequence.\n\n",cs++);
        else
            printf("Case #%d: It is not a B2-Sequence.\n\n",cs++);
    }
}

