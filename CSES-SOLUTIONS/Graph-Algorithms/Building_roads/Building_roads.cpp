#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define lop(i,a,b,c) for(int i=a;i<b;i+=c)
#define rlop(i,a,b,c) for(int i=a-1;i>=b;i-=c)
#define f(i,n) lop(i,0,n,1)
#define rf(i,n) rlop(i,n,0,1)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define endl "\n"
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#define fastread ios::sync_with_stdio(false);cin.tie(0)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
const int MAX = 1e7+10;
const int intmax = LONG_MAX;
const int intmin = LONG_MIN;
 
void _print(int t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(string t) {cerr << t;}
 
template <class T> void _print(vector<T> v) {cerr << "[ "; for(T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set<T> v) {cerr << "[ "; for(T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset<T> v) {cerr << "[ "; for(T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(pair<T,V> p) {cerr << "{"; _print(p.S); cerr << ","; _print(p.F); cerr << "}";}
template <class T, class V> void _print(map<T,V> v) {cerr << "[ "; for(auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
/* ---------------------------------------------------------------------------------- */
map<int,list<int>> adj;
int vis[100001];
 
void dfs(int node)
{
    vis[node] = 1;
    stack<int> st;
    st.push(node);
    while(!st.empty())
    {
        node = st.top();
        st.pop();
 
        for(auto i:adj[node])
        {
            if(!vis[i])
            {
                st.push(i);
                vis[i] = 1;
            }
        }
    }
}
void solve()
{
    int n,m; cin >> n >> m;
 
    f(i,m)
    {
        int x,y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vi ans;
    lop(i,1,n+1,1)
    {
        if(!vis[i])
        {
            ans.pb(i);
            dfs(i);
        }
    }
    cout << ans.size()-1 << endl;
    f(i,ans.size()-1)
    {
        cout << ans[i] << " " << ans[i+1] << endl;
    }
}
int32_t main()
{
    fastread;
    // int t; cin >> t;
    int t=1;
    while(t--) solve();
    return 0;
}