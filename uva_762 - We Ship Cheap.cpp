/*
     Saddam Hossain shishir
     shishir.cse.hstu@gmail.com
*/
#include<bits/stdc++.h>
using namespace std;
map<string,int>Mp;
map<int,string>Mp_str;

#define siz 100001
vector<int>graph[siz];
vector<int>print_paths;
int visited[siz],paths[siz],distanc[siz];
int node;
void bfs(int src)
{
    queue<int>qq;
    qq.push(src);
    visited[src]=1;

    while(!qq.empty())
    {
        int i,u=qq.front();
        qq.pop();
        for(i=0; i<graph[u].size(); i++)
        {
            int v=graph[u][i];
            if(visited[v]==0) // visited[v]=0 means v is new node
            {

                visited[v]=1;  // marking v as visitedited
                distanc[v]=distanc[u]+1;
                paths[v]=u;
                qq.push(v);
            }
        }
    }
}
int get_node(string str)
{
    int u;
    if(Mp[str]==0)
    {
        node++;
        u = node;
        Mp[str]=node;
    }
    else
    {
        u=Mp[str];
    }
    return u;
}
void print_path(int src, int des)
{
    while(des!=src )
    {
        print_paths.push_back(des);
        des=paths[des];
    }
    print_paths.push_back(des);
    reverse(print_paths.begin(), print_paths.end());

    for(int i=0; i<print_paths.size()-1; i++)
        cout<<Mp_str[print_paths[i]]<<' '<<Mp_str[print_paths[i+1]]<<endl;
}
int main()
{
    int i,n,u,v,src,des,cs=0;

    string str,str2;
    while(scanf("%d",&n)==1)
    {
        if(cs==1)
        {
            printf("\n");
        }
        cs=1;
        node=0;
        for(i=0; i<n; i++)
        {
            cin>>str>>str2;

            u=get_node(str);
            Mp_str[u]=str;

            v=get_node(str2);
            Mp_str[v]=str2;

            graph[u].push_back(v);
            graph[v].push_back(u);

        }
        cin>>str>>str2;
        src=get_node(str);
        des=get_node(str2);
        bfs(src);
        if(distanc[des]==0)
        {
            printf("No route\n");
        }
        else
        {
            print_path(src,des);
        }
        for(i=0; i<=node; i++) graph[i].clear();
        memset(visited,0,sizeof visited);
        memset(distanc,0,sizeof distanc);
        memset(paths,0,sizeof paths);
        print_paths.clear();
        Mp.clear();
        Mp_str.clear();
    }


}
