#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
string s1,s2;
int main()
{
    long long  i,j,n,k,r;
    while(getline(cin,s1))
    {
        if(s1=="DONE")
            return 0;
        else
        {
            n=s1.size();
            for(i=0; i<n; i++)
            {
                if(isalpha(s1[i]))
                {
                    s2+=tolower(s1[i]);
                }
            }
            s1=s2;
            reverse(s2.begin(),s2.end());
            if(s1==s2)
                cout<<"You won't be eaten!\n";
            else
                cout<<"Uh oh..\n";
            s1=s2="";
        }
    }
}
