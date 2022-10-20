#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;


void solve()
{
     ll n;
     cin >> n;
     ll arr[n];
     ll m[n];
     for (ll i = 0; i <  n; i++)
          cin >> arr[i];

     fill(m, m + n, 0);

     ll sum = 0;

     for (ll i =  0; i <  n; i++)
     {
          sum += arr[i];
          m[(sum % n + n) % n]++;
     }

     ll ans = 0;
     for (ll i =  0; i <  n; i++)
     {
          if (m[i] > 1)
               ans += (m[i] * (m[i] - 1)) / 2;
     }

     ans += m[0];

     cout << ans;

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
