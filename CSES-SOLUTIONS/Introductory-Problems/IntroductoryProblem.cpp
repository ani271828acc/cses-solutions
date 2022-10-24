#include <bits/stdc++.h>
#include <iostream>
#define mod 10000007
using namespace std;
#define ull unsigned long long int
#define ll long long


int main()
{
    ll a, sum = 0;
    cin >> a;
    ll arr[a - 1];
    for (int i = 0; i < a - 1; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    cout << (((a * (a + 1)) / 2) - sum) << endl;
    return 0;
}
