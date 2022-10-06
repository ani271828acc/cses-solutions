#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> ar[1000001];
int in[1000001];vector<int> res;
void kahn(int n)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
        q.push(i);
    }
    while(!q.empty())
    {
        int curr=q.front();
        res.push_back(curr);
        q.pop();
        for(int node:ar[curr])
        {
            in[node]--;
            if(in[node]==0)
            q.push(node);
        }
    }
if(res.size()!=n)
cout<<"IMPOSSIBLE\n";
else
for(int x:res)
cout<<x<<" ";
 
}
 
int main()
{
    int n,m,x,y;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        ar[x].push_back(y);//directed graph
        in[y]++;
    }
    kahn(n);
}