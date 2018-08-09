#include<stdio.h>
#include<string.h>
 int a[3005],k,i,j,ck,n,h;
int main()
{
    while(scanf("%d",&n)==1)
    {
        ck=0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }

        for(i=0; i<n-1; i++)
        {
            for(j=i+1; j<n; j++)
            {
                if(a[i]>a[j])
                {
                    k=a[i];
                    a[i]=a[j];
                    a[j]=k;
                }
            }
        }
        h=a[n-1]-a[n-2];
        for(i=n-2; i>=1; i--)
        {
            if(a[i]-a[i-1]==h)
            {
                ck=1;
            }
            else
            {
                ck=0;
                break;
            }
        }
        if(ck==1)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;

}

