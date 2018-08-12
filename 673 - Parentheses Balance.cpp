
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

#define pii pair<int,int>
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
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
map<ll,bool>visi;
bool vis[10001];
int main()
{
    //freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    int  i,j,n,m,a,c,r,b,ck,t,x,y,z,ans,rem,cnt,lo,hi,sum,cs=1;
    string st;
    scanf("%d%*c",&t);
    while(t--)
    {
        getline(cin,st);
        r=0;
        n=st.size();
        while(r<n)
        {
            ck=0;
            if(r<0)
                r=0;
            if(st[r]=='(')
            {
                if(st[r+1]==')')
                {
                    st.erase(st.begin()+r);
                    st.erase(st.begin()+r);
                    r--;
                    ck=1;
                }
            }
            if(st[r]=='[')
            {
                if(st[r+1]==']')
                {
                    st.erase(st.begin()+r);
                    st.erase(st.begin()+r);
                    ck=1;
                    //ans+=2;
                    r--;
                }
            }
            if(ck==0)
                r++;
        }
        if(st.size()==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
}

