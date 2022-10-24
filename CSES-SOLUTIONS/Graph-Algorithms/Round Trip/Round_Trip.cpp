#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define int long long
#define double long double
#define lop(i,a,b,c) for(int i=a;i<b;i+=c)
#define rlop(i,a,b,c) for(int i=a-1;i>=b;i-=c)
#define f(i,n) lop(i,0,n,1)
#define rf(i,n) rlop(i,n,0,1)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define endl "\n"
#define mem0(a) memset(a , 0 , sizeof(a))
#define mem1(a) memset(a , 1 , sizeof(a))
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#define fastread ios::sync_with_stdio(false);cin.tie(0)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
const int MAX = 1e7+10;
const int intmax = LLONG_MAX;
const int intmin = LLONG_MIN;
 
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
map<int,bool> vis;
stack<int> st;
int en;
int parents[100005];
vi ans;
bool isc(int node,int parent)
{
    vis[node] = 1;
 
    ans.pb(node);
    for(auto it:adj[node])
    {
        if(it==parent) continue;
        if(vis[it])
        {
            ans.pb(it);
            return true;
        }
        else if(isc(it,node))
        {
            return true;
        }
    }
    ans.pop_back();
    return false;
}
 
int32_t main()
{
    fastread;
    int n,m; cin >> n >> m; f(i,m){int x,y; cin >> x >> y; adj[x].pb(y); adj[y].pb(x);}
    bool iscycle = 0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i] && isc(i,-1))
        {
            iscycle = 1;
            break;
        }
    }
    if(!iscycle)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
 
    n = ans.size();
    int last = ans[n-1];
    bool chk = 0;
    for(int i=0;i<n;i++)
    {
        if(ans[i]==last && chk==0)
        {
            chk=1;
            cout << n-i << endl;
        }
        if(chk==0) continue;
        cout << ans[i] << " ";
    }
    return 0;
}