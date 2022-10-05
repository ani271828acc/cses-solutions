#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n,q; cin >> n >> q;
    vector <vector<int>> p(30,vector<int>(n+1,0));
 
    for(int i = 0; i<n; i++){
        cin >> p[0][i+1];
    }
 
    for(int j = 1; j<30; j++){
        for(int i = 1; i<n+1; i++){
            p[j][i] = p[j-1][p[j-1][i]];
        }
    }
 
    int x,k,c(0); 
    while(q--){
        cin >> x >> k; 
        c = 0;
        while(k){
           if(k%2){
              x = p[c][x];
           }
           c++;
           k /= 2;
        }
        cout << x << endl;
    }
 
	return 0;
}
