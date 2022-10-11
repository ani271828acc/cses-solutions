#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n, input, sum = 0;
    cin >> n;

    for (int i = 0 ; i < n - 1 ; i++) {
        cin >> input;
        sum += input;
    }

    cout << ( n * (n + 1) ) / 2 - sum << endl;

    return 0;
}
