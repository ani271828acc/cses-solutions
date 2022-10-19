#include<bits/stdc++.h>
typedef long long ll;
#define V(a) vector<a>
#define P(a,b) pair<a,b>
#define A(a) set<a>
#define M(a,b) map<a,b>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define in insert
#define bp __builtin_popcount
#define ppb pop_back
#define FOR(a,b,c) for(ll(a) = b; a < c; a++)
#define FORN(a,b,c) for(ll(a) = b; a <= c; a++)
#define FOREV(a,b,c) for(ll(a)=b; a > c; a--)
#define FOREVN(a,b,c) for(ll(a)=b; a >= c; a--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
 
bool cprime(int x)
{
    if (x == 1)
        return false;
    if (x <= 3)
        return true;
    if (x % 2 == 0 || x % 3 == 0)
        return false;
    for (int i = 5; i <= sqrt(x); i += 6)
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    return true;
}
 
bool cpalin(string s)
{
    int n = s.length(), l;
    if (n == 1)
        return true;
    if (n % 2 == 0)
        l = n / 2 - 1;
    else
        l = (n - 1) / 2 - 1;
    for (int i = 0; i <= l; i++)
        if (s[i] != s[n - i - 1])
            return false;
    return true;
}
void sieveOfEratosthenes(int n)
{
    bool arr[n + 1];
    FOR(i, 0, n + 1)
    arr[i] = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i] == true)
        {
            for (int j = i * i ; j <= n; j += i)
            {
                if (arr[j] == true)
                    arr[j] = false;
            }
        }
    }
}
 
ll ndivs(ll n)
{
    int N = 1000;
    bool arr[N];
    FOR(i, 0, N)
    arr[i] = true;
    for (int i = 2; i * i <= N; i++)
    {
        if (arr[i] == true)
        {
            for (int j = i * i ; j <= N; j += i)
            {
                if (arr[j] == true)
                    arr[j] = false;
            }
        }
    }
 
    ll p = 1;
    FOR(i, 2, N)
    {
        if (arr[i] == true && n % i == 0)
        {
            ll m = 0; ll cp = n;
            while (cp % i == 0)
            {
                cp /= i;
                m++;
            }
            p *= (m + 1);
        }
    }
    return p;
}
bool compare( ll a,  ll b) // false return swap
{
    return a > b;
}
 
 
ll power( ll a, ll b)
{
    ll p = 1;
    ll N = 1e9+7;
    while (b > 0)
    {
        if (b & 1)
            p = (p%N * a%N)%N;
        a = (a%N*a%N)%N;
        b >>= 1;
    }
    return p;
}
 
string dtobin(ll n)
{
    string s;
    while (n)
    {
        s = to_string((n % 2)) + s;
        n /= 2;
    }
    return s;
}
 
ll bintod(string s)
{
    ll n = 0;
    FOR(i, 0, s.length())
    if (s[i] == '0')
        continue;
    else
        n += pow(2, (s.length() - 1 - i));
    return n;
}
 
ll sdigs(ll n)
{
    int s = 0;
    while (n)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}
 
ll fact(ll p)
{
    int x = 1;
    FORN(i, 1, p)
    x *= i;
 
    return x;
}
ll ncr(ll n , ll r)
{
    ll ans = (fact(n) ) / (fact(r) * fact(n - r));
    return ans;
}
 
ll __lcm(ll a, ll b)
{
    ll g = __gcd(a,b);
    return (a*b)/g;
}
int main() {
 
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
  
  ll N = 1e6+7 ; 
  ll arr[N+1] = {0};
  for(ll i = 1; i <= N; i++)
  {
    for(ll j = 1; i*j <= N; j++)
        arr[j*i]++;
  }
 
  ll t;
  cin >> t;
  while(t--)
  {
 
  ll n;
  cin >> n;
  cout  << arr[n] << "\n";
 
    } 
      return 0;
}
 
