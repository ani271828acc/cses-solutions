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
#define fastread() ios::sync_with_stdio(false);cin.tie(0)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
const int MAX = 1e7+10;
const int intmax = INT_MAX;
const int intmin = INT_MIN;
 
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
 
int32_t main()
{
    fastread();
    int n; cin >> n;
    char a[n+1][n+1];
    lop(i,1,n+1,1) lop(j,1,n+1,1) cin >> a[i][j];
    int dp[n+1][n+1];
    f(i,n+1) f(j,n+1)
    {
        if(i==0 || j==0) dp[i][j] = 0;
        else if(i==1 && j==1) dp[i][j] = a[i][j]=='*'?0:1;
        else if(a[i][j]=='*') dp[i][j] = 0;
        else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        dp[i][j] %= MOD;
    }
    cout << dp[n][n] << endl;
    return 0;
}