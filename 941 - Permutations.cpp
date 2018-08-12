
#include <iostream>
#include<cstring>
#include <algorithm>
using namespace std;
int main ()
{
    char a[100];
    int i,l,n,r,t;
    cin>>t;
    while(t--)
    {
        cin>>a>>n;
        l=strlen(a);
        i=0;
        r=1;
        do
        {
            if(r==n+1)
            {
                for(i=0; i<l; i++)
                {
                    cout<<a[i];
                }
                cout<<endl;
                break;
            }
            r++;
        }
        while ( next_permutation(a,a+l));
    }
    return 0;

}
