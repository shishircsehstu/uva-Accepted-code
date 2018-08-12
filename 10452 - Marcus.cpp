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

#define pb push_back
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
int dx[]= {0,0,-1};/*3 side move*/
int dy[]= {-1,1,0};/*3 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
map<ll,bool>visi;
int vis[101][101];
char str[101][101];
int row,col,cnt=1;
vector<string>vec2;
string str2;
int indi;
int bfs(int x,int y,vector<string>vec,int r)
{
    int i;
    // cout<<"r=="<<r<<endl;
    if(r==6)
    {
        //  cout<<x<<" "<<y<<endl<<endl;
        if(str[x][y+1]=='#')
            vec.pb("right");
        else if(str[x-1][y]=='#')
            vec.pb("forth");
        else if(str[x][y-1]=='#') vec.pb("left");
        for(i=0; i<vec.size(); i++)
        {
            cout<<vec[i];
            if(i<vec.size()-1)
                printf(" ");
        }
        printf("\n");
    }
    for(i=0; i<3; i++)
    {
        int x1=dx[i]+x;
        int y1=dy[i]+y;
        if(x1<=row&&x1>=1&&y1<=col&&y1>=1&&str[x1][y1]!='#'&&vis[x1][y1]==0)
        {
            if(r==0&&str[x1][y1]=='I')
            {
                if(y==y1+1)
                {
                    vec.pb("left");
                }
                else if(y==y1-1)
                {
                    vec.pb("right");
                }
                else if(x==x1+1)
                    vec.pb("forth");
                vis[x1][y1]=1;
                bfs(x1,y1,vec,r+1);
            }
            else if(r==1&&str[x1][y1]=='E')
            {
                if(y==y1+1)
                {
                    vec.pb("left");
                }
                else if(y==y1-1)
                {
                    vec.pb("right");
                }
                else if(x==x1+1)
                    vec.pb("forth");
                vis[x1][y1]=1;
                bfs(x1,y1,vec,r+1);
            }
            if(r==2&&str[x1][y1]=='H')
            {
                if(y==y1+1)
                {
                    vec.pb("left");
                }
                else if(y==y1-1)
                {
                    vec.pb("right");
                }
                else if(x==x1+1)
                    vec.pb("forth");
                vis[x1][y1]=1;
                bfs(x1,y1,vec,r+1);
            }
            if(r==3&&str[x1][y1]=='O')
            {
                if(y==y1+1)
                {
                    vec.pb("left");
                }
                else if(y==y1-1)
                {
                    vec.pb("right");
                }
                else if(x==x1+1)
                    vec.pb("forth");
                vis[x1][y1]=1;
                bfs(x1,y1,vec,r+1);
            }
            if(r==4&&str[x1][y1]=='V')
            {
                if(y==y1+1)
                {
                    vec.pb("left");
                }
                else if(y==y1-1)
                {
                    vec.pb("right");
                }
                else if(x==x1+1)
                    vec.pb("forth");
                vis[x1][y1]=1;
                bfs(x1,y1,vec,r+1);
            }
            if(r==5&&str[x1][y1]=='A')
            {
                if(y==y1+1)
                {
                    vec.pb("left");
                }
                else if(y==y1-1)
                {
                    vec.pb("right");
                }
                else if(x==x1+1)
                    vec.pb("forth");
                vis[x1][y1]=1;
                bfs(x1,y1,vec,r+1);
            }
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    int  i,j,n,m,a,c,r,b,ck,t,x,y,z,ans,rem,lo,hi,sum,cs=1;
    vector<string>vec;
    scanf("%d",&t);
    while(t--)
    {
        indi=0;
        scanf("%d%d",&row,&col);
        for(i=1; i<=row; i++)
        {
            for(j=1; j<=col; j++)
            {
                cin>>str[i][j];
                if(str[i][j]=='@')
                {
                    x=i;
                    y=j;
                }
            }
        }
        vis[x][y]=1;
        bfs(x,y,vec,0);
        mem(vis);
        vec.clear();
    }
}

