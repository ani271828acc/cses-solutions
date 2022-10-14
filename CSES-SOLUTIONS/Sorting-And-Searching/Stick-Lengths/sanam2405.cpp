#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;


void solve()
{
     ll n;
     cin >> n;

     vector<ll> v(n);

     for (ll i = 0; i < n; i++)
          cin >> v[i];

     sort(v.begin(), v.end());

     ll mid = n / 2;
     if (n & 1)
     {
          ll median = v[mid];

          ll ans = 0;

          for (auto &x : v)
               ans += abs(x - median);

          cout << ans;
     }
     else
     {
          ll median1 = v[mid];
          ll median2 = v[mid - 1];

          ll ans1 = 0;
          ll ans2 = 0;

          for (auto &x : v)
          {
               ans1 += abs(x - median1);
               ans2 += abs(x - median2);
          }

          cout << min(ans1, ans2);
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
