
#include <bits/stdc++.h>

using namespace std;
#define ll              long long
#define pll             pair<ll,ll>
#define F               first
#define S               second

//PBDS
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pll, null_type, less_equal<pll>, rb_tree_tag, tree_order_statistics_node_update>
    ordered_set;
void myerase(ordered_set &t, pll v){
    int rank = t.order_of_key(v);
    ordered_set::iterator it = t.find_by_order(rank); 
    t.erase(it);
}
// ----------how to use PBDS-------- dont uncomment this
// find_by_order() return the iterator to the element at xth(0-based) position
// order_of_key() returns number of elements in set which are strictly less than x

void solve(ll test_case){
 
    ll n; cin >> n;
 
    ordered_set s;
 
    for( int i = 1; i < n + 1; i++ ){
        ll x; cin >> x;
        s.insert( { i, x } );
    }
 
    for( int i = 0; i < n; i++ ){
        ll x; cin >> x;
        x--;
        auto it = s.find_by_order(x);
        pll k = *(it);
        cout << k.S << " ";
        myerase(s, k);
    }
 
 
} 
 
int main(){
 
    ll ttcc = 1;
    ll test_case=1;
    while(ttcc--){
        solve(test_case);
        test_case++;
    }
}
