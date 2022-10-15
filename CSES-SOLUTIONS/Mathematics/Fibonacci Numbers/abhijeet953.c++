#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const ll mod = 1e9 + 7;
map<ll, ll> mat; // cause range of n is from 1 to 1e18

ll fib(ll n)
{
    if (mat.count(n))
        return mat[n];
        
    ll k = n / 2;

    if (n & 1)
        return mat[n] = (fib(k) * fib(k + 1) + fib(k - 1) * fib(k)) % mod;
    else
        return mat[n] = (fib(k) * fib(k) + fib(k - 1) * fib(k - 1)) % mod;
}

int main()
{
    ll n;
    cin >> n;
    mat[0] = 1;
    mat[1] = 1;
    if (n == 0)
        cout << 0 << endl;
    else
        cout << fib(n - 1) << endl;
}
