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
double ar[100001];
#include<bits/stdc++.h>
using namespace std;
struct two
{
    int a;
    double b;
} nm[1001];
bool cmp(two x,two y)
{
    if(x.b==y.b)
    {
        return x.a<y.a;
    }
    else
        return x.b>y.b;
}
/*
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>nm[i].a>>nm[i].b;
    puts("\n");
    sort(nm,nm+n,cmp);
    for(int i=0; i<n; i++)
        printf("%d %d\n",nm[i].a,nm[i].b);
}
*/
int main()
{
    //freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    int n,i,t;
    scanf("%d",&t);
    while(t--)
    {
        double x,y;
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            scanf("%lf%lf",&x,&y);
            ar[i]=y/x;
        }
        for(i=0 ; i<n; i++)
        {
            nm[i].a=i+1;
            nm[i].b=ar[i+1];
        }
        sort(nm,nm+n,cmp);
        for( i=0; i<n; i++)
        {
            printf("%d",nm[i].a);
            if(i<n-1)
                printf(" ");
        }
        printf("\n");
        if(t!=0)
            printf("\n");
    }
}
