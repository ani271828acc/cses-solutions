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
const int N = 1e6 + 1;
 
void solve(){
    int dp[N+1][2];
    dp[0][0] = 1;
    dp[0][1] = 1;
    Fo(i,1,N+1){
        dp[i][0] = dp[i-1][1];
        fo(j,2){
            dp[i][0] += dp[i-1][0];
            dp[i][0] %= mod;
        }
        
        dp[i][1] = dp[i-1][0];
        fo(j,4){
            dp[i][1] += dp[i-1][1];
            dp[i][1] %= mod;
        }
    }
    ll t,a; cin >> t;
    while(t--){
        cin >> a;
    ll ans = dp[a-1][0] + dp[a-1][1];
    ans %= mod;
    cout << ans << endl;
    }
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
