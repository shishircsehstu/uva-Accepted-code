/******************************************************************
 *                   BISMILLAHIR RAHMANIR RAHIM                   *
 *                     Saddam Hossain shishir                     *
 *       Hajee Mohammad Danesh Science & Technology University    *
 *                                                                *
 ***************************************************************** */
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
#include<limits>
#include<limits.h>

#define all(v) v.begin(),v.end()

#define sc scanf
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%I64d",&t)

#define sii(a,b) scanf("%d%d",&a,&b)

#define P(a) printf("%d\n",a)
#define PLN(a) printf("%I64d ",a)
#define pf printf

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second

#define pb push_back
#define pii pair<int,int>
#define mk make_pair
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
#define mod 100000007

#define faster      ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
using namespace std;

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48


//upper bound and lower bound

#define LB(a,value) (lower_bound(all(a),value)-a.begin())
#define UB(a,value) (upper_bound(all(a),value)-a.begin())
//S.insert(lower_bound(S.begin( ),S.end( ),x),x); //S is vector

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int ar[siz],m,n,cnt,vis[15];
int dig1,dig2;
int lol(int a,int b)
{
    dig1=dig2=0;
    int x;
    mem(vis);
    while(a>0)
    {
        x=a%10;
        vis[x]++;
        if(vis[x]>1)
            return 1;
        a/=10;
        dig1++;
    }
    while(b>0)
    {
        x=b%10;
        vis[x]++;
        if(vis[x]>1)
            return 1;
        b/=10;
        dig2++;
    }
    return 0;
}
int zero(int a,int b)
{
    while(a>0)
    {
        if(a%10==0) return 1;
        a/=10;
    }
    while(b>0)
    {
        if(b%10==0) return 1;
        b/=10;
    }
    return 0;
}
int main()
{

    //freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int i,x,y,ck,kk;
    kk=0;
    while(si(n)==1)
    {
        if(n==0) break;
        ck=0;
        if(kk==1) printf("\n");
        for(i=1000; i<=100000; i++)
        {
            x=n*i;
            if(x>100000) continue;
            y=lol(x,i);
            if(dig1==4 and dig2==4) continue;
            if(y==0)
            {
                if(dig2==4)
                {
                    y=zero(x,i);
                    if(y==1) continue;
                }
                ck=1;
                printf("%d / ",x);
                if(dig2==4)
                    printf("0");
                printf("%d = %d\n",i,n);
            }
        }
        if(ck==0)
            printf("There are no solutions for %d.\n",n);
        kk=1;
    }

}

