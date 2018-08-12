#include<stdio.h>
#include<string.h>
#include<ctype.h>
char ar[2000],ar1[2000],ar2[2000],ar3[200],ar4[100];
int r,t,i,j,m;
void abc(void)
{
    int len,w,h;
    t++;
    ar1[j]='\0';
    ar4[m]='\0';
    if(ar1[0]=='a'||ar1[0]=='A'||ar1[0]=='e'||ar1[0]=='E'||ar1[0]=='i'||ar1[0]=='I'||ar1[0]=='o'||ar1[0]=='O'||ar1[0]=='u'||ar1[0]=='U')
    {
        printf("%s",strcat(ar1,"ay"));
        printf("%s",ar4);
    }
    else
    {
        w=0;
        len=strlen(ar1);
        ar3[0]=ar1[0];
        ar3[1]='\0';
        for(h=1; h<len; h++)
        {
            ar2[w]=ar1[h];
            w++;
        }
        ar2[w]='\0';
        strcat(ar2,ar3);
        printf("%s",strcat(ar2,"ay"));
        printf("%s",ar4);
    }

    j=0;
    m=0;
    if(t<r+1)
    {
        printf(" ");
    }
    else
    {
        printf("\n");
        t=0;
        r=0;
    }
}
int main()
{
    int n,k;
    while(gets(ar))
    {
        n=strlen(ar);
        for(k=0; k<n; k++)
        {
            if(ar[k]==' ')
            {
                r++;
            }
        }
        j=0;
        for(i=0; i<=n; i++)
        {
            if(ar[i]==' '||ar[i]=='\0')
            {
                abc();
            }
            else
            {
                if(!isalpha(ar[i]))
                {
                    ar4[m]=ar[i];
                           m++;
                }
                else
                {
                    ar1[j]=ar[i];
                    j++;
                }
            }
        }
    }
    return 0;
}

