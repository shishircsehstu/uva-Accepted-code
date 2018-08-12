//BISMILLAHIR RAHMANIR RAHIM
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<set>
#include<cmath>
#include<cctype>
#include<stack>
#include<cstdlib>
#include<utility>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>

//input
#define si(t) scanf("%d",&t)
#define sll(t) scanf("%I64d",&t)
#define sll2(a,b) scanf("%I64d %I64d",&a,&b)
#define sf(t) scanf("%f",&t)
#define sd(t) scanf("%lf",&t)
#define sii(a,b) scanf("%d%d",&a,&b)

//Output
#define P(a) printf("%d\n",a)
#define PL(a) printf("%lldn",a)
#define PF(a) printf("%fn",a)
#define PDB(a) printf("%lfn",a)
#define PLL(a) printf("%I64d\n",a)
#define PP(a,b) printf("%d %dn",a,b)
#define PPN(a,b) printf("%d %d ",a,b)
#define PPL(a,b) printf("%lld %lldn",a,b)
#define PPLN(a,b) printf("%lld %lld ",a,b)

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second

#define pf printf
#define sc scanf
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl
#define pii pair<int,int>
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;
#define mx 1000010
#define mod 1000000007
int row,col;
int ar[siz];
int ar2[siz];
int test[siz];
set<int>S;
int happy(int n)
{
    test[0]=0;
    int s,i,sum,cnt,n1,r,ck;
    cnt=1;
    r=1;
    n1=n;
    ck=0;
    while(1)
    {
        sum=0;
        if(n==1)
            cnt=0;
        while(n>0)
        {
            s=n%10;
            n/=10;
            sum+=s*s;
        }
        cnt++;
        n=sum;
        if(n==1)
        {
            ar[n1]=1;
            ar2[n1]=cnt;
            break;
        }
        else
        {
            for(i=0; i<r; i++)
            {
                if(sum==test[i])
                {
                    ck=1;
                    break;
                }
            }
        }
        if(ck==1)
            break;
        test[r++]=sum;
    }
}
void read()
{
    int i;
    for(i=1; i<=99999; i++)
        happy(i);
}
int main()
{
    read();
    int i,j,n,k,ck,lo,hi;
    ck=0;
    while(sc("%d%d",&lo,&hi)==2)
    {
        if(ck==1)
            pf("\n");
        ck=1;
        for(i=lo; i<=hi; i++)
        {
            if(ar[i]==1)
            {
                pf("%d %d\n",i,ar2[i]);
            }
        }
    }
}

