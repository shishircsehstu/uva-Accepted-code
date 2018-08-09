#include<cstdio>
#include <cstdlib>
#include <ctime>
#include<vector>
#include <functional>
#include <iostream>
#include <queue>
typedef long long  li;
using namespace std;

int main()
{
    li n;
    while (cin>>n)
    {
        if(n==0)
            return 0;
        priority_queue<li, vector<li>, greater<li> > q;
        while (n--)
        {
            li x;
            cin>>x;
            q.push(x);
        }
        li t = 0, cost = 0;
        while (q.size()>1)
        {
            t = q.top();
            q.pop();
            t += q.top();
            q.pop();
            cost += t;

            q.push(t);
        }
        cout<<cost<<endl;
    }
}
