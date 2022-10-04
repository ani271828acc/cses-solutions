#include <bits/stdc++.h>
 
 
#define fast      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll              long long
#define ull             unsigned long long
#define tct             ll tct; cin>>tct; while(tct--)
 
// _________________________________________________________________________________________________________________
//COMMON DATA STRUCTURES
//----------------------
 
#define vll             vector<ll>
#define vstring         vector<string>
#define vpairll         vector<pair<ll,ll>>
#define mpll            map<ll,ll>
#define mpcl            map<char,ll>
#define setll           set<ll>
#define msetll          multiset<ll>
#define dq              deque<ll>
 
// ________________________________________________________________________________________________________________
//COMMON OPERATIONS 
//-----------------
 
#define setbits         __builtin_popcountll //count number of 1 in binary
#define leadzero        __builtin_clz //count leading zeroes in binary
#define tailzero        __builtin_ctz //coutn tail zero
#define pb              push_back
#define popb            pop_back
#define pfrt            push_front
#define popfrt          pop_front
#define lb              lower_bound
#define ub              upper_bound
#define gcd             __gcd
#define F               first
#define S               second
#define endl            "\n"
#define all(v)          v.begin(),v.end()
#define revall(v)       v.end(),v.begin()
#define MEM(a, b)       memset(a, (b), sizeof(a))    
#define loop(i,a,b)     for(ll i=a;i<b;i++)
#define rev(i,a,b)      for(ll i=b-1;i>=a;i--)
#define foreach(it,l)   for(auto it=l.begin();it!=l.end();it++)
#define reveach(it,l)   auto it = l.end();it--;for(it;it!=l.begin();l--)
 
 
#define PI           3.1415926535897932384626433832795
const ll N      =    1e9+7;
const ll i1     =    1e6+5;
 
using namespace std;
 
   
// ________________________________________________________________________________________________________________
 
//CODE HERE..........
 
 
void kkkuuu(){
    
    ll n; cin>>n;
   
    ll arr[n];
    loop(i,0,n)
    cin>>arr[i];
    sort(arr,arr+n);
    loop(i,0,n){
        if(arr[i+1]-arr[i] != 1){
            cout<<arr[i]+1;
            break;
        }
        
    }
 
 
}
 
int main(){
    fast;
    
    kkkuuu();
        
    
        
        
 
 
 
 
}
