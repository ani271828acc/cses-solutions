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
 
int dp[1000005];
 
int func(int a[],int n,int k)
{
    if(k==0) return 1;
    if(dp[k]!=-1) return dp[k];
    int ans = 0;
    f(i,n)
    {
        if(a[i]<=k)
        ans += func(a,n,k-a[i]);
        ans %= MOD;
    }
    return dp[k] = ans%MOD;
}
void solve()
{
    mem1(dp);
    int n,k; cin >> n >> k;
    int a[n];
    f(i,n) cin >> a[i];
    cout << func(a,n,k);
}
 
int32_t main()
{
    fastread;
    // int t; cin >> t;
    int t=1;
    while(t--) solve();
    return 0;
}