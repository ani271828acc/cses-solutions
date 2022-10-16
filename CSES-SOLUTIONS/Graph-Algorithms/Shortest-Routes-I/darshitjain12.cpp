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
const ll mod = 1e18;
const ll N = 2e5;
 
void solve(){
    ll n,m,a,b,c; cin >> n >> m;
    vpll adj[n];
    while(m--){
       cin >> a >> b >> c;
       adj[--a].pb({--b,c});
    }
    vl d(n,mod);
    priority_queue <pll,vpll,greater<pll>> q;
    d[0] = 0;
    q.push({0,0});
    while(q.size()){
        pll p = q.top(); q.pop();
        if(p.F != d[p.S]){continue;}
        for(auto x:adj[p.S]){
            if(d[x.F]>x.S+d[p.S]){
                d[x.F] = x.S + d[p.S];
                q.push({d[x.F],x.F});
            }
        }
    }
    OUT(d); 
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
