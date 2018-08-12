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
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl
#define pb push_back
#define pii pair<int,int>
#define mk make_pair
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
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


map<ll,bool>visi;
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
ll n,sum;
vector<ll>vec,vec2,xx,vec3,vec4;
vector<ll> sub_set_sum(vector<ll>va)
{
    xx.clear();
    int len,i,j,x,ind;
    ll sum;
    n=va.size();
    for(i=0; i<1<<n; i++)
    {
        sum=0;
        for(j=0; j<n; j++)
        {
            if(i&(1<<j))
                sum+=va[j];
        }
        xx.pb(sum);
    }
    return xx;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll  i,j,m,a,c,b,d,ck,t,r,x,ans,rem,cnt,lo,hi,cs=1;
    while(scanf("%lld %lld",&n,&sum)==2)
    {
        for(i=1; i<=n; i++)
        {
            scanf("%lld",&x);
            if(i<=n/2) vec.pb(x);
            else
                vec2.pb(x);
        }
        vec3=sub_set_sum(vec);
        vec4=sub_set_sum(vec2);
        sort(vec4.begin(),vec4.end());
        a=0;
        for(i=0; i<vec3.size(); i++)
        {
            x=vec3[i];
            rem=sum-x;
            hi=upper_bound(vec4.begin(),vec4.end(),rem)-vec4.begin();
            lo=lower_bound(vec4.begin(),vec4.end(),rem)-vec4.begin();
            //cout<<lo<<"  "<<hi<<endl;
            a+=(hi-lo);
        }
        if(sum==0) a--;
        printf("%lld\n",a);
        vec.clear(),vec2.clear();
    }


}
/*
6 0
-1 2 -3 4 -5 6
5 0
-7 -3 -2 5 8

*/
