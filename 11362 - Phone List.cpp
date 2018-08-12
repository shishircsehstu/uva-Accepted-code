#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cctype>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<utility>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
#define ff first
#define ss second
#define sc scanf
#define pf printf
#define endl '\n'
#define pii pair(int,int)
#define pi acos(-1.0)
#define siz 1000001
#define one(x) __builtin_popcount(x)
typedef long long li;
using namespace std;
struct node
{
    bool endmark;
    node *next[26+1];
    node()
    {
        endmark=false;
        for(int i=0; i<10; i++)
            next[i]=NULL;
    }
}*root;

int  insert(char *str,int len)
{
    node *curr=root;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'0';
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        if(curr->endmark==true)
            return true;
        curr=curr->next[id];
    }
    curr->endmark=true;
    for(int i=0; i<10; i++)
    {
        if(curr->next[i]!=NULL)
            return true;
    }
    return false;
}
void del(node *cur)
{
    for(int i=0; i<10; i++)
    {
        if(cur->next[i])
            del(cur->next[i]) ;
    }
    delete(cur) ;
}
int main()
{
    int n,m,t,r,cs=1;
    char str[11];
    sc("%d",&t);
    while(t--)
    {
        root=new node();
        int num_word;
        cin>>num_word;
        m=0;
        for(int i=1; i<=num_word; i++)
        {
            if(m==0)
            {
                scanf("%s",str);
                r=(insert(str,strlen(str)));
                if(r==1)
                    m=1;
            }
            else
                sc("%s",str);
        }
        pf("Case %d: ",cs++);
        if(m==1)
            pf("NO\n");
        else
            pf("YES\n");
        del(root);
    }
    return 0;
}

