#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

vector<int> manacher(string _s){
    string s="@";
    for(auto v:_s){
        s+=v;
        s+="#";
    }
    s.back()='&';
    int n=(int)s.length();
    vector<int> ans(n-1,0);
    int lo=0,hi=0;
    for(int i=1;i<n-1;i++){
        if(i!=1){
            ans[i]=min(hi-i,ans[hi-i+lo]);
        }
        while(s[i-ans[i]-1]==s[i+ans[i]+1])ans[i]++;
        if(i+ans[i]>hi){
            lo=i-ans[i];
            hi=i+ans[i];
        }
    }
    ans.erase(begin(ans));
    for(int i=0;i<(int)ans.size();i++){
        if(i%2==ans[i]%2)++ans[i];
    }
    return ans;
}
void solve(){
    string s;
    cin>>s;
    auto b=manacher(s);
    int ans=0,idx=-1;
    for(int i=0;i<(int)b.size();i++){
        if(ans<b[i]){
            ans=b[i];
            idx=i;
        }
    }
    string ok="";
    if(idx%2==1){
        idx/=2;
        idx++;
        idx-=(ans/2);
        cout<<s.substr(idx,ans)<<endl;
    }else{
        idx/=2;
        idx-=(ans/2);
        cout<<s.substr(idx,ans)<<endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}