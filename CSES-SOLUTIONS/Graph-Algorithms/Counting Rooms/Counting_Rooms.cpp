#include <bits/stdc++.h>
using namespace std;
vector<vector<char>>grid;
vector<vector<int>>vis;
 
 
void dfs(int i,int j){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='#' || vis[i][j]){
        return;
    }
    // cout<<i<<j<<endl;
    vis[i][j] = 1;
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i,j-1);
}
int main()
{
  int n,m;
  cin>>n>>m;
  int count=0;
  for(int i=0;i<n;i++){
    vector<char>temp;
    for (int j = 0; j < m; j++)
    {
        char t;
        cin>>t;
        temp.push_back(t);
       
        
    }
    grid.push_back(temp);
    
  }
  vis = vector<vector<int>>(grid.size(),vector<int>(grid[0].size()));
  for(int i=0;i<n;i++){
    for (int j = 0; j < m; j++){
       if(grid[i][j]=='.' && vis[i][j]==0){
        count++;
        dfs(i,j);
       }
 
    }
}
   
 
   cout<<count<<endl;
 
 
  
return 0;
}