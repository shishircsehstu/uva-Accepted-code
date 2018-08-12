#include<iostream>
#include<utility>
#include<cstring>
#include<queue>
#define uu first
#define vv second
#include<vector>
#define pii pair<int,int>
using namespace std;
int fx[]= {2,-2,0,0};
int fy[]= {0,0,2,-2} ;
int fx1[]= {0,0,0,0,1,-1,1,-1};
int fy1[]= {1,-1,1,-1,0,0,0,0};
int cell[100][100];
int d[100][100],vis[100][100];
int row,col;
void bfs(int sx,int sy)
{
    int j,r;
    memset(vis,0,sizeof vis);
    vis[sx][sy]=1;
    queue<pii>q;
    q.push(pii(sx,sy));
    while(!q.empty())
    {
        pii top=q.front();
        q.pop();
        j=r=0;
        for(int k=0; k<4; k++)
        {
            for(; j<r+2; j++)
            {
                int tx=top.uu+fx[k]+fx1[j];
                int ty=top.vv+fy[k]+fy1[j];
                if(tx>=1&&tx<=row &&ty>=1 &&ty<=col &&cell[tx][ty]!=-1&&vis[tx][ty]==0)
                {
                    vis[tx][ty]=1;
                    d[tx][ty]=d[top.uu][top.vv]+1;
                    q.push(pii(tx,ty));
                }
            }
            r=j;
        }
    }
}
int main()
{
    row =col=8;
    int x,ro1,co1,ro2,co2;
    char c1,c2;
    while(cin>>c1>>ro1)
    {
        co1=c1-96;
        bfs(ro1,co1);
        cin>>c2>>ro2;
        co2=c2-96;
        cout<<"To get from "<<c1<<ro1<<" to "<<c2<<ro2<<" takes "<<d[ro2][co2]<<" knight moves.\n";
        memset(d,0,sizeof d);
    }
}
