#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;


void solve()
{
     ll n, q;
     cin >> n >> q;
     ll arr[n];
     for (ll i =  0; i <  n; i++)
          cin >> arr[i];

     ll ps[n + 1];
     fill(ps, ps + n + 1, 0);

     ps[0] = 0;
     for (ll i =  0; i <  n; i++)
          ps[i + 1] = ps[i] + arr[i];

     while (q--)
     {
          ll a, b;
          cin >> a >> b;
          cout << ps[b] - ps[a - 1] << "\n";
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
