#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;


void solve()
{

     string s;
     cin >> s;
     ll cnt = 0;
     vector<string> v;
     sort(s.begin(), s.end());
     do {
          v.push_back(s);
          cnt++;
     } while (next_permutation(s.begin(), s.end()));
     cout << cnt << "\n";
     for (auto &x : v)
          cout << x << "\n";
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
