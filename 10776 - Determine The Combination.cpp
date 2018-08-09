#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
typedef long long li ;
using namespace std;
vector<char>v;
li pred[100],n,len;
void pe(char s[])
{
    li i,j,k;
    if(v.size()==n)
    {
        for(i=0; i<n; i++)
            printf("%c",v[i]);
        printf("\n");
        return;
    }
    for(i=0; i<len; i++)
    {
        if(!v.empty()&&v[v.size()-1]>s[i])
            continue;
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
int main()
{
    li i,j,k;
    char  s[100];
    while(cin>>s>>n)
    {
        len=strlen(s);
        sort(s,s+len);
        pe(s);
        v.clear();
    }
}

