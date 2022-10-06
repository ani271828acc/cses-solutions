#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    set<int> mst;
    for(int i=0;i<n;i++){
        mst.insert(i+1);
    }    
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        mst.erase(x);
    }    


    cout<<*mst.begin()<<endl;
}
