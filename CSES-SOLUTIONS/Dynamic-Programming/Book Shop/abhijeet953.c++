#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int n, x;
    cin >> n >> x;
    int h[n];
    int s[n];
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int j = 0; j < n; j++)
        cin >> s[j];
    int dp[n + 1][x + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < x + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < x + 1; j++)
        {
            if (h[i - 1] <= j)
            {
                dp[i][j] = max(s[i - 1] + dp[i - 1][j - h[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << (dp[n][x]) << endl;
}