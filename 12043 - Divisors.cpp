#include<iostream>
#include<vector>
using namespace std;
#define mx 100001
typedef long long ll;
vector<int>v2[mx];
int ar[mx];
int ar1[mx];
void divi()
{
    ll i,j,n,k;
    for(i=1; i<=mx; i++)
    {
        for(j=i; j<=mx; j+=i)
        {
            ar[j]+=i;
            v2[j].push_back(i);

        }
    }
}
int main()
{
    divi();
    ll lo,hi,di,i,sum,sum1,t;
    cin>>t;
    while(t--)
    {
        cin>>lo>>hi>>di;
        sum=sum1=0;
        for(i=lo; i<=hi; i++)
        {
            if(i%di==0)
            {
                sum+=ar[i];
                sum1+=v2[i].size();
            }
        }
        cout<<sum1<<' '<<sum<<endl;
    }
    return 0;
}

