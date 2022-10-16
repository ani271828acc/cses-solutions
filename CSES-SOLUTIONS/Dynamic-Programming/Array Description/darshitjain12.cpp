#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(ll i=0;i<n;i++)
#define Fo(i,k,n) for(ll i=k;i<n;i++)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%I64d",&x)
#define ss(s)	scanf("%s",s)
#define pb push_back
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define all(x) x.begin(), x.end()
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << " " << x << "\n";
#define INP(v) for(auto &x:v){cin >> x;}
#define OUT(v) for(auto &x:v){cout << x << " ";}
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
const ll mod = 1000000007;
const ll N = 2e5;
 
void solve(){
    ll n,m; cin >> n >> m;
    vl a(n); INP(a);
    ll dp[n][m+2] = {};
    if(!a[0]){
        fo(i,m){
            dp[0][i+1] = 1;
        }
    }
    else{
        dp[0][a[0]] = 1;
    }
 
    Fo(i,1,n){
        if(!a[i]){
        Fo(j,1,m+1){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1];
            dp[i][j] %= mod;
        }
        }
        else{
            dp[i][a[i]] = dp[i-1][a[i]] + dp[i-1][a[i]+1] + dp[i-1][a[i]-1];
            dp[i][a[i]] %= mod; 
        }
    }
    ll ans = 0;
    fo(i,m+1){
        ans += dp[n-1][i];
        ans %= mod;
    }
    cout << ans << endl;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    ll darshit = 1;
    
    for(ll i=1;i<=darshit;i++)
    {
    //cout <<"Case #" << i <<": ";  
    solve();
    }
 
 
	return 0;
}
