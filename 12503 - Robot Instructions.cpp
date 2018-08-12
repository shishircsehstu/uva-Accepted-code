#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    char str[100][100];
    char s[100],s1[100];
    int i,j,n,sum,t,n1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n1);
        sum=0;
        for(i=1; i<=n1; i++)
        {
            scanf("%s",str[i]);
            strcpy(s,str[i]);
            if(!strcmp(s,"SAME"))
            {
                scanf("%s%d",s1,&n);
                strcpy(str[i],str[n]);
            }
        }
        for(i=1; i<=n1; i++)
        {
            strcpy(s,str[i]);
            if(!strcmp(s,"RIGHT"))
                ++sum;
            else
                --sum;
        }
        printf("%d\n",sum);
    }
}

