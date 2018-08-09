#include<stdio.h>
#include<math.h>
int main()
{
    double red,num,ap,i,are;
    while(scanf("%lf%lf",&red,&num)==2)
    {
        ap=red*cos(3.141592654/num);
        are=ap*ap*num*tan(3.141592654/num);
        printf("%.3lf\n",are);
    }
}
