//Maximum absolute difference between any two elements

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        int n,s;
        cin>>n>>s;
        int second;
        int maxdiff=INT_MIN,diff;
        for(int i=0;i<=min(n,s);i++)
        {
            second=s-i;
            if(second+i==s)
              if(second<=n)
                diff=abs(second-i);
            else
            continue;
            if(diff>maxdiff)
            maxdiff=diff;
        }
        cout<<maxdiff<<endl;
    }
    return 0;
}
