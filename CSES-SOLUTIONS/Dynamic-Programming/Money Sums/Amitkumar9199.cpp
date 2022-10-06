#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"


void solve(){
    int n;
    cin>>n;
    std::vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    set<int> st={0};
    for(int i=0;i<n;i++){
        vector<int> m;
        for(auto u:st){
            m.push_back(u+v[i]);
        }
        for(auto u:m){
            st.insert(u);
        }
    }
    st.erase(st.begin());
    cout<<st.size()<<" ";
    for(auto u:st){
        cout<<u<<" ";
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}