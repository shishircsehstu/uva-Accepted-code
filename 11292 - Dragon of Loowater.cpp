//BISMILLAHIR RAHMANIR RAHIM
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<set>
#include<cmath>
#include<cctype>
#include<stack>
#include<cstdlib>
#include<utility>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>

#define sc scanf
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%I64d",&t)
#define sii(a,b) scanf("%d%d",&a,&b)

#define P(a) printf("%d\n",a)
#define PLN(a) printf("%I64d ",a)
#define pf printf

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl

#define pii pair<int,int>
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;
//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
map<ll,bool>visi;
vector<int>vec[500000];
int ar[20001];
int ar2[20001];
int main()
{
    int i,j,hed,x,y,kni,sum;
    while(scanf("%d%d",&hed,&kni)==2)
    {
        if(hed==0&&kni==0)
            break;
        for(i=0; i<hed; i++)
            scanf("%d",&ar[i]);
        for(i=0; i<kni; i++)
            scanf("%d",&ar2[i]);
        if(hed>kni)
            printf("Loowater is doomed!\n");
        else
        {
            sort(ar,ar+hed);
            sort(ar2,ar2+kni);
            int h,k;
            sum=h=k=0;
            while(1)
            {
                if(ar[h]>ar2[k])
                    k++;
                else
                {
                    sum+=ar2[k];
                    //cout<<ar2[k]<<"h"<<endl;
                    k++;
                    h++;
                }
                if(kni==k||hed==h)
                    break;
            }
            if(h==hed)
                printf("%d\n",sum);
            else
                printf("Loowater is doomed!\n");
        }
    }
}

