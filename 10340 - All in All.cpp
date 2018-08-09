#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100],c[100];
    int i,j,ln,ln2,ck,m,h;
    while(scanf("%s%s",a,b)==2)
    {
        ck=0;
        m=0;
        h=0;
        ln=strlen(a);
        ln2=strlen(b);
        for(i=0; i<ln; i++)
        {
            for(j=0+m; j<ln2; j++)
            {
                if(a[i]==b[j])
                {
                    ck=1;
                    m=j;
                    c[h]=b[j];
                    h++;
                    break;
                }
            }
        }
        c[h]='\0';
        if(!strcmp(a,c))
            printf("Yes\n");
        else
            printf("No\n");
    }
}

