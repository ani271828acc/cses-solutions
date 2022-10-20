#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ll power( ll a, ll b)
{
     ll p = 1;
     ll N = 1e9 + 7;
     while (b > 0)
     {
          if (b & 1)
               p = (p % N * a % N) % N;
          a = (a % N * a % N) % N;
          b >>= 1;
     }
     return p;
}

void solve()
{
     ll n;
     cin >> n;
     while (n--)
     {
          ll a, b;
          cin >> a >> b;
          cout << power(a, b) << "\n";
     }
}



int main() {

#ifndef ONLINE_JUDGE
     freopen("Input.txt", "r", stdin);
     freopen("Output.txt", "w", stdout);
#endif

     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);
     cout.tie(nullptr);

     ll t;
     t = 1;
     // cin >> t;
     while (t--)
     {
          solve();
     }

     return 0;
}
