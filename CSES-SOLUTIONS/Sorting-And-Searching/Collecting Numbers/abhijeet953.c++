#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int maxN = 2e5+1;
int pos[maxN];
 
int main()
{
    int n;
    cin>>n;
   
    for(int i=1;i<=n;i++)
    {
       int x;cin>>x;
        pos[x]=i;
    }
 
    int count=1;
    for(int i=2;i<=n;i++)
    {
        if(pos[i-1]>pos[i])
        count++;
    }
 
    cout<<count<<endl;
 
}