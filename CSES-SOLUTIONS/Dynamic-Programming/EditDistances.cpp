#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>&dp, string s, string t, int i, int j){
        // base case
        
        if(i == s.length()){
            return t.length() - j;
        }
        if( j == t.length()){
            return s.length() - i;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        
        if(s[i] == t[j]){
            return solve(dp,s,t,i+1,j+1);
        }
        else{
            int inserted = 1 +solve(dp,s,t,i,j+1);
            int deleted = 1 +solve(dp, s,t, i+1, j);
            int replace = 1 +solve(dp, s,t, i+1, j+1);
            
            dp[i][j] = min(inserted, min(deleted, replace));
            
        }
        return dp[i][j];
    }
        
  
    int editDistance(string s, string t) {
        // Code here
        vector<vector<int>>dp(s.length(), vector<int>(t.length(), -1));
        return solve(dp,s,t,0,0);
    }

int main(){
  string s,t;
  cin>>s>>t;
  cout<<editDistance(s,t)<<endl;
  return 0;
}
