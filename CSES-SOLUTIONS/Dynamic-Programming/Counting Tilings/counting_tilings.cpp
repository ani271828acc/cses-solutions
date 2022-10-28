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
 
 
void generateMasks(int mask, int n, int newMask, int idx, vector<int>&next_masks) {
 
	if (idx == n) {
		next_masks.push_back(newMask);
		return;
	}
 
	if (!(mask & (1 << idx))) {
		// either use first operation
		generateMasks(mask, n, newMask | (1 << idx), idx + 1, next_masks);
 
		// or use second operation
 
		if (idx + 1 < n && !(mask & (1 << (idx + 1)))) {
			generateMasks(mask, n, newMask, idx + 2, next_masks);
		}
 
	}
	else {
		generateMasks(mask, n, newMask, idx + 1, next_masks);
	}
 
}
 
void solve() {
	int n, m; cin >> n >> m;
	// dp on broken profile
 
	// dp[i][maks] = no. of ways to fill i columns completely, such that mask represent the state of i+1th column
	vector<vector<int>>dp(m + 1, vector<int>(1 << n));
 
	dp[0][0] = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < (1 << n); j++) {
			// from dp[i][j] => which states are reachable
			// find masks which are reachable from here
			vector<int>next_masks;
			generateMasks(j, n, 0, 0, next_masks);
			for (auto mask : next_masks) {
				dp[i + 1][mask] = (dp[i + 1][mask] + dp[i][j]) % mod;
			}
 
		}
	}
 
	cout << dp[m][0] << endl;
 
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
