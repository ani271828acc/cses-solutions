#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
 
    if (n < 0) // Negative Number Edge Case
        return -1;
 
    // Initialize result
    int count = 0;
 
    // Keep dividing n by powers of
    // 5 and update count
    for (int i = 5; i<=n; i *= 5)
        count += n / i;
 
    cout<<count<<endl;
}
 

