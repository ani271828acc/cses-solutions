#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;


void solve()
{

     ll x;
     cin >> x;
     for (ll n = 1; n <= x; n++)
     {
          ll ans = (n * n * (n * n - 1)) / 2 - 4 * (n - 1) * (n - 2);
          cout << ans << "\n";
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
