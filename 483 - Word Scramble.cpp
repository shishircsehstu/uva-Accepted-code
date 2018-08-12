#include<stdio.h>
#include<string.h>
char ar[2000],ar1[2000];
int r,t,i,j;
void abc()
{
    t++;
    ar1[j]='\0';
    printf("%s",strrev(ar1));
    j=0;
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
                ar1[j]=ar[i];
                j++;
            }
        }
    }
    return 0;
}

