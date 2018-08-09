#include<stdio.h>
#include<string.h>
int main()
{
    char k,a[1004],b[1004],c[1004],d[1004];
    int n1,n2,i,j,h,r,ck,n3,n4,k1;
    while(gets(a))
    {
        gets(b);
        n1=strlen(a);
        for(i=0; i<n1-1; i++)
        {
            for(j=i+1; j<n1; j++)
            {
                if(a[i]>a[j])
                {
                    k=a[i];
                    a[i]=a[j];
                    a[j]=k;
                }
            }
        }
        ck=1;
        j=1;
        r=0;
        for(i=0,j=1; i<n1; i++)
        {
            if(a[i]==a[j])
            {
                ck=0;
                j++;
            }
            else
            {
                c[r]=a[i];
                j++;
                r++;
                ck=1;
            }
        }
        c[r]='\0';
        n2=strlen(b);
        for(i=0; i<n2-1; i++)
        {
            for(j=i+1; j<n2; j++)
            {
                if(b[i]>b[j])
                {
                    k=b[i];
                    b[i]=b[j];
                    b[j]=k;
                }
            }
        }
        ck=1;
        j=1;
        r=0;
        for(i=0,j=1; i<n2; i++)
        {
            if(b[i]==b[j])
            {
                ck=0;
                j++;
            }
            else
            {
                d[r]=b[i];
                j++;
                r++;
                ck=1;
            }
        }
        d[r]='\0';
        n3=strlen(c);
        n4=strlen(d);
        if(n3>n4)
        {
            for(i=0; i<n4; i++)
            {
                for(j=0; j<n3; j++)
                {
                    if(d[i]==c[j])
                    {
                        printf("%c",d[i]);
                    }

                }
            }
        }
        else
        {
            for(r=0; r<n3; r++)
            {
                for(h=0; h<n4; h++)
                {
                    if(c[r]==d[h])
                    {
                        printf("%c",c[r]);
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}





