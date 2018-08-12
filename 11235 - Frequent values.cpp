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
#define siz 5*1000001
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
int ar[siz],ar2[siz];
int tree[siz];
map<int,int>freq;
void build_tree(int node,int s,int e)
{
    if(s==e)
    {
        tree[node]=ar2[s];
        return;
    }
    build_tree(node*2,s,(s+e)/2);
    build_tree(node*2+1,(s+e)/2+1,e);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}
int query(int node, int a, int b, int i, int j)
{
    int q1,q2,res;
    if(a > b || a > j || b < i) return -99999999;
    if(a >= i && b <= j)
        return tree[node];
    q1 = query(node*2, a, (a+b)/2, i, j);
    q2 = query(1+node*2, 1+(a+b)/2, b, i, j);
    res  = max(q1, q2);
    return res;
}
int main()
{
    //freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    int  i,j,n,m,a,c,b,ck,t,x,y,ans,rem,cnt,lo,hi,sum,cs=1;
    while(scanf("%d",&n)==1)
    {
        mem(tree);
        freq.clear();
        if(n==0)
            break;
        si(m);
        for(i=1; i<=n; i++)
        {
            si(x);
            freq[x]++;
            ar[i]=x;
        }
        for(i=1; i<=n; i++)
        {
            x=ar[i];
            ar2[i]=freq[x];
            //  cout<<ar2[i]<<" ";
        }
        build_tree(1,1,n);
        //  cout<<query(1,1,n,2,3)<<endl;
        for(j=0; j<m; j++)
        {
            si(x);
            si(y);
            int cnt1,cnt2;
            cnt1=cnt2=i=0;
            while(ar[x]==ar[x+1] and x<=y)
            {
                x++;
                cnt1++;
            }
            if(x<=y)
            {
                cnt1++;
                x++;
            }
            while(ar[y]==ar[y-1] and y>=x)
            {
                y--;
                cnt2++;
            }
            if(y>=x)
            {
                y--;
                cnt2++;
            }
            if(x>y)
                printf("%d\n",max(cnt1,cnt2));
            else
            {
                x=query(1,1,n,x,y);
                printf("%d\n",max(x,max(cnt1,cnt2)));
            }
        }
    }
}

