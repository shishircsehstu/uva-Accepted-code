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
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 10001
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
/*
uva 11871, same as uva 836
AC code
*/
map<ll,bool>visi;
int ar[siz];
stack<int>st;
int arr[2007][2007];
int arr2[2003];
int histogram( int n,int ar[])
{
    int i,rem,ans;
    i=1;
    rem=0;
    ans=0;
    int id;
    while(i<=n)
    {
        if(st.empty()||ar[st.top()]<=ar[i])
            st.push(i++);
        else
        {
            id=st.top();
            st.pop();
            if(st.empty())
                ans=ar[id]*(i-1);
            else
                ans=ar[id]*(i-st.top()-1);
        }
        rem=max(ans,rem);
    }

    while(!st.empty())
    {
        id=st.top();
        st.pop();
        if(st.empty())
            ans=ar[id]*(i-1);
        else
            ans=ar[id]*(i-st.top()-1);
        rem=max(ans,rem);
    }
    return rem;
}
int main()
{
    //freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int  i,j,n,m,a,c,b,ck,t,x,r,y,k,ans,rem,cnt,lo,hi,sum,cs=1;
    si(t);
    while(t--)
    {
        mem(arr2);
        si(m),si(n);
        for(i=1; i<=m; i++)
        {
            r=1;
            si(k),si(c);
            sum=0;
            for(j=1; j<=k; j++)
            {
                si(x);
                while(x--)
                {
                    arr[i][r]=c;
                    r++;
                }
                if(c==1)
                    c=0;
                else
                    c=1;
            }
        }
        ans=0;
        for(i=1; i<=m; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(arr[i][j]==0)
                    arr2[j]++;
                else
                    arr2[j]=0;
            }
            //for(j=1;j<=n;j++) cout<<arr2[j]<<" ";
            // cout<<endl;
            x=histogram(n,arr2);
            // cout<<x<<endl;
            ans=max(ans,x);

        }
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;


}
