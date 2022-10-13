#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

vector<string> v;
void TOH(int n, int a, int b, int c)
{
     if (n > 0) {
          TOH(n - 1, a, c, b);
          string s = to_string(a) + " " + to_string(c);
          v.push_back(s);
          TOH(n - 1, b, a, c);
     }

}
void solve()
{

     ll n;
     cin >> n;
     TOH(n, 1, 2, 3);
     cout << v.size() << "\n";
     for (ll i = 0; i < v.size(); i++)
          cout << v[i] << "\n";
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
