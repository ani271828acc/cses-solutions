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
map<int,bool> vis;
map<int,list<int>> adj;
map<int,int> parent;
// stack<int> st;
vi v; bool chk = 0;
 
void bfs(int node,int n)
{
    queue<int> q;
    q.push(node);
 
    vi dist(n+1,intmax);
    dist[1] = 0;
 
    while(!q.empty())
    {
        node = q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(dist[node]+1<dist[it])
            {
                dist[it] = dist[node]+1;
                q.push(it);
                parent[it] = node;
            }
        }
    }
}
int shortestdist(int src,int n)
{
    vi dist(n+1,intmax);
    dist[1] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(dist[node]+1<dist[it])
            {
                dist[it] = dist[node]+1;
                q.push(it);
            }
        }
    }
    for(auto it:dist)
    {
        // cout << it << " ";
    }
    return dist[n];
}
void solve()
{
    int n,m; cin >> n >> m;
    f(i,m)
    {
        int x,y; cin >> x >> y;
        adj[x].pb(y); adj[y].pb(x);
    }
    int shorty = shortestdist(1,n);
    if(shorty==intmax)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    // dfs(1,shorty);
    shorty++;
    cout << shorty << endl;
    bfs(1,n);
    vi ans; int node = n; parent[1] = -1;
    while(node!=-1)
    {
        ans.pb(node);
        node = parent[node];
    }
    reverse(all(ans));
    for(auto it:ans)
        cout << it << " ";
}
int32_t main()
{
    fastread;
    // int t; cin >> t;
    int t=1;
    while(t--) solve();
    return 0;
}