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
map<string,int>mpp;

void cal()
{
    mpp["JAN"]=mpp["MAR"]=mpp["MAY"]=mpp["JUL"]=mpp["AUG"]=mpp["OCT"]=mpp["DEC"]=31;
    mpp["FEB"]=28;
    mpp["APR"]=mpp["JUN"]=mpp["SEP"]=mpp["NOV"]=30;
    mpp["SUN"]=1;
    mpp["MON"]=2;
    mpp["TUE"]=3;
    mpp["WED"]=4;
    mpp["THU"]=5;
    mpp["FRI"]=6;
    mpp["SAT"]=7;
}
string st,st2;
char str[12],str2[23];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,m,i,j,a,b,x,y,ck,t,r,rem,cnt,lo,ans,hi,sum,cs=1;
    cal();
    si(t);
    while(t--)
    {
        scanf("%s %s",str,str2);
        st=str,st2=str2;
        x=mpp["SAT"]-mpp[st2]+1;
        ans=0;
        if(x>=2) ans+=2;
        else if(x==1) ans++;
        x=mpp[st]-x;
        sum=7;
        while(1)
        {

            if(sum-1<=x) ans++;
            if(sum<=x) ans++;
            if(sum>x) break;

            sum+=7;
        }
        printf("%d\n",ans);
    }

}
/*
3
JAN WED
*/
