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

#define P(a) prllf("%d\n",a)
#define PLN(a) prllf("%I64d ",a)
#define pf prllf

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl

#define pii pair<ll,ll>
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;
//ll dx[]= {-1,-1,0,0,1,1};
//ll dy[]= {-1,0,-1,1,0,1};
//ll dx[]= {0,0,1,-1};/*4 side move*/
//ll dy[]= {-1,1,0,0};/*4 side move*/
//ll dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//ll dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//ll dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//ll dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
map<ll,bool>visi;
queue<ll>q1,q2;
ll ar[1001],n;
int cal()
{
    ll i,x,y;
    q1.push(ar[0]+ar[1]);
    q1.push(ar[0]-ar[1]);
    q1.push(ar[0]*ar[1]);
    for(i=2; i<5; i++)
    {
        x=ar[i];
        while(!q1.empty())
        {
            y=q1.front();
            q2.push(y+x);
            q2.push(y-x);
            q2.push(y*x);
            q1.pop();
        }
        q1=q2;
        while(!q2.empty())
            q2.pop();
    }
    while(!q1.empty())
    {
        if(q1.front()==23)
        {
            return 1;
        }
        q1.pop();
    }
    //prllf("Yes\n");
    return 0;
}
int main()
{
    //freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    ll i,j,m,a,c,b,ck,t,x,y,ans,rem,cnt,lo,hi,sum,cs=1;
    while(scanf("%lld",&ar[0])==1)
    {
        for(i=1; i<5; i++)
            scanf("%lld",&ar[i]);
        if(ar[0]==0&&ar[1]==0&&ar[2]==0&&ar[3]==0&&ar[4]==0)
            break;
        /// cal();
        sort(ar,ar+5);
        do
        {
            // cout<<"yes\n";
            while(!q1.empty())
                q1.pop();
            // cout<<"yes\n";
            //cout<<ar[0]<<ar[1]<<ar[2]<<ar[3]<<ar[4]<<endl;
            ck=cal();
            //prllf("%d ck=\n",ck);
            if(ck==1)
            {
                printf("Possible\n");
                break;
            }
        }
        while ( next_permutation(ar,ar+5));
        if(ck==0)
            printf("Impossible\n");

    }
}



