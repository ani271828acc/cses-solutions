#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;


void solve()
{

     string s;
     cin >> s;
     int arr[26];
     for (ll i = 0; i < 26; i++)
          arr[i] = 0;
     for (ll i = 0; i < s.length(); i++)
          arr[s[i] - 'A']++;
     int c = 0;
     for (ll i = 0; i < 26; i++)
     {
          if (arr[i] & 1)
               c++;
     }
     if (c > 1) {
          cout << "NO SOLUTION";
          return;
     }

     string m, ans, str;
     for (ll i = 0; i < 26; i++)
     {
          if (arr[i] & 1)
               m += (char) (i + 'A');
          arr[i] /= 2;
          while (arr[i])
          {
               str += (char) (i + 'A');
               arr[i]--;
          }
     }
     ans += str + m;
     reverse(str.begin(), str.end());
     ans += str;
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
