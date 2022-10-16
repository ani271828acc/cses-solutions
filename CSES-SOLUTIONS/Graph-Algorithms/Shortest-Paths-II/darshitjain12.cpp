 #include <bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
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
const ll INF = 1e18;
 
void solve(){
    ll n,m,q; cin >> n >> m >> q;
    ll a,b,c;
    vvl d(n+1,vl(n+1,INF));
    Fo(i,1,n+1){d[i][i] = 0;}
    while(m--){
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b],c);
        d[b][a] = min(d[b][a],c);
    }
    Fo(k,1,n+1){
        Fo(i,1,n+1){
            Fo(j,1,n+1){
                if(d[i][k]<INF && d[k][j]<INF)
                    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    while(q--){
        cin >> a >> b;
        if(d[a][b]==INF){cout << -1 << endl;continue;}
        cout << d[a][b] << endl;
    }
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    ll darshit = 1;
    
    for(ll i=1;i<=darshit;i++)
    {
    solve();
    }
 
 
	return 0;
}
