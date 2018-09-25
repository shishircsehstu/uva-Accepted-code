#include<bits/stdc++.h>

#define all(v) v.begin(),v.end()
#define sc scanf
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%I64d",&t)

#define sii(a,b) scanf("%d%d",&a,&b)

#define pt(a) printf("%d\n",a)
#define PLN(a) printf("%I64d\n",a)
#define pf printf

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second

#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 300001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
#define mod 100000009
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
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
/* -a%b---------
ll  Mod(ll  a,ll  b)
{
    ll  c = a % b;
    return (c < 0) ? c + b : c;
}
/*
ll  power(ll num,ll p)
{
    int i;
    ll sum=1;
    for(i=1; i<=p; i++)
        sum*=num;
    return sum;
}
*/
string st;
ll ar[siz];
void fib()
{
    ar[1]=1;
    ar[2]=2;
    for(int i=3; i<=50; i++)
        ar[i]=ar[i-1]+ar[i-2];
}

int main()
{
    // faster
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int  n,i,j,a,b,x,y,ck,t,r,rem,cnt,lo,hi,sum,cs=1;
    int k;
    int ans[87] = { 1, 18, 10, 11, 7, 17, 11, 15, 29, 5, 21, 13, 26, 14, 11, 23,
                    22, 9, 73, 17, 42, 7, 98, 15, 61, 22, 84, 24, 30, 9, 38, 15, 54, 27,
                    9, 61, 38, 22, 19, 178, 38, 53, 79, 68, 166, 20, 9, 22, 7, 21, 72,
                    133, 41, 10, 82, 92, 64, 129, 86, 73, 67, 19, 66, 115, 52, 24, 22,
                    176, 10, 57, 137, 239, 41, 70, 60, 116, 81, 79, 55, 102, 49, 5, 22,
                    54, 52, 113, 15
                  };

    while (scanf("%d", &r), r)
    {
        printf("%d\n",ans[r-13]);


    }
}
/*
S = 1 or S = 4 or S = 78
• negative result S = S35
• experiment failed S = 9S4
• experiment not completed S = 190S

+ for a positive result
- for a negative result
* for a failed experiment
?
*/
