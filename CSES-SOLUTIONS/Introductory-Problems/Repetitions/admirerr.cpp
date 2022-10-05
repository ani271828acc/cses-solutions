#include<bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int mx=1;
    int curr=1;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]){
            curr++;
        }
        else if(s[i]!=s[i-1]){
            curr=1;
        }
        mx=max(curr,mx);
    }
    cout<<mx;
    return 0;
}
