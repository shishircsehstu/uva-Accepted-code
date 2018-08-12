#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<map>
using namespace std;
#define mx 1000001
map< string,vector<string> > G;
string ar[mx];
string ar1[mx];
map<string,string> parent;
map<string,int>level;
map<string,int>visited;
int r1=0;
void bfs1(string n,string src)
{
    string y;
    int r=0;
    y=n;
    while(y!=src )
    {
        ar[r++]=y;
        y=parent[y];
    }
    ar[r++]=src;
    reverse(ar,ar+r);
    for(int i=0; i<r-1; i++)
        cout<<ar[i]<<' '<<ar[i+1]<<endl;
}
void bfs(string  n,string  src)
{
    queue<string>Q;
    Q.push(src);
    visited[src]=1;
    level[src]=0;
    while(!Q.empty())
    {
        string u=Q.front();
        if(G[u].size()!=0)
            ar1[r1++]=u;
        for(int i=0; i<G[u].size(); i++)
        {
            string v=G[u][i];
            if(!visited[v])
            {
                parent[v]=u;
                visited[v]=1;
                Q.push(v);
            }
        }
        Q.pop();
    }

}
int main()
{
    int i,j,k,n,cn,cn1,r=0;
    string x,y;
    set<string>st;
    while(cin>>n)
    {
        if(r==1)
            cout<<endl;
        r=1;
        for(i=0; i<n; i++)
        {
            cin>>x>>y;
            G[x].push_back(y);
            st.insert(x);
            st.insert(y);
            G[y].push_back(x);
        }
        cin>>x>>y;
        bfs(y,x);
        cn=count(ar1,ar1+r1,x);
        cn1=count(ar1,ar1+r1,y);
        if(cn==0||cn1==0)
            cout<<"No route\n";
        else
        {
            bfs1(y,x);
        }
        set<string>::iterator t;
        for(t=st.begin(); t!=st.end(); t++)
        {
            G[*t].clear();
        }
        st.clear();
        level.clear();
        parent.clear();
        visited.clear();
        r1=0;
    }
    return 0;
}

