#include<bits/stdc++.h>
#define siz  1001
#define pii pair<int,int>
using namespace std;
//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};

int dx[]= {0,0,1,-1};/*4 side move*/
int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

int row,col;
int visited[siz][siz], distanc[siz][siz];
void bfs(int src_x,int src_y)
{

    visited[src_x][src_y]=1;
    queue<pii>q;
    distanc[src_x][src_y]=0;
    q.push(pii(src_x,src_y));

    while(!q.empty())
    {
        pii top=q.front();
        q.pop();

        for(int k=0; k<4; k++)
        {
            int v_x=top.first+dx[k];
            int v_y=top.second+dy[k];

            if(v_x>=0&&v_x<row &&v_y>=0 &&v_y<col&&visited[v_x][v_y]==0)
            {
                visited[v_x][v_y]=1;
                distanc[v_x][v_y]=distanc[top.first][top.second]+1;
                q.push(pii(v_x,v_y));
            }
        }
    }
}
int main()
{

    int line,n,pos_x,pos_y,src_x,src_y,des_x,des_y;
    while(scanf("%d%d",&row,&col))
    {
        if(row ==0 && col==0)
            return 0;
        scanf("%d",&line);
        for(int i=0; i<line; i++)
        {
            scanf("%d",&pos_x);
            scanf("%d",&n);
            for(int j=0; j<n; j++)
            {
                scanf("%d",&pos_y);
                visited[pos_x][pos_y]=1;
            }
        }
        scanf("%d%d%d%d",&src_x,&src_y,&des_x,&des_y);
        bfs(src_x,src_y);
        printf("%d\n",distanc[des_x][des_y]);
        memset(visited,0,sizeof visited);
        memset(distanc,0,sizeof distanc);

    }

}
