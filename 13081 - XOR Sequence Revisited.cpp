#include<stdio.h>
int main()
{
    long long t,i,a,b,sum,n,x,y,z,ck;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        if(a==0&&b==0)
        {
            printf("1\n");
        }
        else
        {
            ck=0;
            for(i=a; i<=b; i++)
            {
                if(i%4==1)
                {
                    printf("0\n");
                    ck=1;
                    break;
                }
            }
            if(ck==0)
            {
                n=(a-1)/4+1;
                sum=1+(n-1)*4;
                if(a-sum==1)
                {
                    x=(n-1)*4+2;
                }
                else if(a-sum==2)
                    x=1;
                else if(a-sum==3)
                    x=(n-1)*4+5;
                if(b-a==2)
                {
                    y=1;
                    z=x+3;
                    printf("%lld\n",x&y&z);
                }
                else if(b-a==1)
                {
                    y=1;
                    printf("%lld\n",x&y);
                }
                else if(b-a==0)
                    printf("%lld\n",x);
            }
        }
    }
    return 0;
}
