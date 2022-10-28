#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define uniq(v)         (v).erase(unique(all(v)),(v).end())
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define pii             pair<int,int>
#define mem1(a)         memset(a,-1,sizeof(a))
#define mem0(a)         memset(a,0,sizeof(a))
#define vi              vector<int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define ps(x,y)         fixed<<setprecision(y)<<x
#define rep(i,a,b)      for(int i=a;i<b;i++)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}
template<typename T>
using pbds = tree<T , null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update>;
const int N = 1e5 + 5;
 
 
void solve() {
	int n; cin >> n;
 
	vector<pair<pii, int>>v(n);
	map<int, int>compression;
	for (int i = 0; i < n; i++) {
		cin >> v[i].ff.ff >> v[i].ff.ss >> v[i].ss;
		compression[v[i].ff.ff];
		compression[v[i].ff.ss];
	}
 
 
	int cnt = 1;
	for (auto &x : compression) {
		x.ss = cnt++;
	}
 
	vector<pii>dm[cnt + 1];
 
	for (int i = 0; i < n; i++) {
		v[i].ff.ff = compression[v[i].ff.ff];
		v[i].ff.ss = compression[v[i].ff.ss];
		debug(v[i]);
		dm[v[i].ff.ss].pb({v[i].ff.ff, v[i].ss});
	}
 
	vector<int>dp(cnt + 1);
	// dp[i] = maximum amount we can generate till day i
 
	for (int i = 1; i <= cnt; i++) {
 
		dp[i] = dp[i - 1];
		for (auto x : dm[i]) {
			if (x.ff - 1 >= 0) {
				amax(dp[i], x.ss +  dp[x.ff - 1] );
 
			}
			else {
				amax(dp[i], x.ss);
			}
		}
	}
 
	cout << dp[cnt] << endl;

}
 
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#ifdef SIEVE
	sieve();
#endif
#ifdef NCR
	init();
#endif
	int t = 1;
	// cin >> t;
	while (t--) solve();
	return 0;
 
}
