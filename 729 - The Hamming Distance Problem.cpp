#include<bits/stdc++.h>
using namespace std;
vector<char>v;
int pred[100],n,len;
void pe(char s[])
{
    int i,j,k;
    if(v.size()==len)
    {
        int ck=1;
        for(i=0; i<len; i++)
            printf("%c",v[i]);
        printf("\n");
        return;
    }
    for(i=0; i<len; i++)
    {
        if(pred[i]==0)
        {
            pred[i]=1;
            v.push_back(s[i]);
            pe(s);
            pred[i]=0;
            v.pop_back();
            while(s[i]==s[i+1])
                i++;
        }
    }
}
string st;
char s[100];
int main()
{
    int i,j,k,n,m,t,ck;
    scanf("%d",&t);
    while(t--)
    {
        memset(pred,0,sizeof pred);
        scanf("%d%d",&n,&m);
        k=n-m;
        for(i=0; i<k; i++)  st+='0';
        for(i=0; i<m; i++) st+='1';
        strcpy(s,st.c_str());
        len=strlen(s);
        pe(s);
        st.clear();
        v.clear();
        if(t>0) printf("\n");
    }
}

