#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define int long long
#define double long double
#define rep(i,a,b,c) for(int i=a;i<b;i+=c)
#define bck(i,a,b,c) for(int i=a-1;i>=b;i-=c)
#define f(i,n) rep(i,0,n,1)
#define rf(i,n) bck(i,n,0,1)
#define fr(i,n) rep(i,1,n+1,1)
#define rfr(i,n) bck(i,n+1,1,1)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define endl "\n"
#define mem0(a) memset(a , 0 , sizeof(a))
#define mem1(a) memset(a , -1 , sizeof(a))
#define memt(a) memset(a , true , sizeof(a))
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#define fastread ios::sync_with_stdio(false);cin.tie(0)
#define ppc __builtin_popcount;
#define ppcll __builtin_popcountll;
 
// typedef tree<int , null_type ,  less_equal<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_multiset;
// typedef tree<int , null_type, less<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_set;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vpii;
typedef pair<int,int> pii;
typedef map<int,int> mii;
const int MOD = 1e9 + 7;
const int MAX = 1e7+10;
const int N = 2e5+5;
const int intmax = LLONG_MAX;
const int intmin = LLONG_MIN;
const int inf = 2e18;
int power(int x, int y, int m = intmax)
{
    int res = 1;
    x = x % m;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % m;
        y = y >> 1LL;
        x = (x * x) % m;
    }
    return res;
}
int mod_inv(int n, int m) {return power(n, m - 2, m);}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mod_inv(b, m), m));}
 
/* ---------------------------------------------------------------------------------- */
int n,m;
map<int,vector<pii>> adj;
map<int,int> vis;
vector<tuple<int,int,int>> edges;
map<int,int> parent;
 
void solve()
{
    cin >> n >> m;
    f(i,m)
    {
        int x,y,z; cin >> x >> y >> z;
        adj[x].pb({y,z});
        edges.pb({x,y,z});
    }
    map<int,int> par;
    vector<int> dist(n+1);
    dist[1] = 0;
    f(i,n-1)
    {
        for(auto j:edges)
        {
            int u = get<0>(j);
            int v = get<1>(j);
            int w = get<2>(j);
            if(dist[u]==INT_MAX) continue;
            if(dist[v]>dist[u]+w)
            {
                dist[v] = dist[u]+w;
                par[v] = u;
            }
        }
    }
    int c = -1;
    for(auto j:edges)
    {
        int u = get<0>(j);
        int v = get<1>(j);
        int w = get<2>(j);
        if(dist[u]==INT_MAX) continue;
        if(dist[v]>dist[u]+w)
        {
            c = v;
            break;
        }
    }
    if(c==-1)
    {
        cout << "NO\n";
        return;
    }
    vi ans;
    f(i,n) c = par[c];
    ans.pb(c);
    int curr=par[c];
    while(curr!=c)
    {
        ans.pb(curr);
        curr = par[curr];
    }
    ans.pb(curr);
    reverse(all(ans));
    cout << "YES\n";
    for(auto i:ans) cout << i << " ";
    cout << endl;
}
int32_t main()
{
    fastread;
    // int t; cin >> t;
    int t=1;
    for(int i=0;i<t;i++)
    {
        solve();
    }
    return 0;
}