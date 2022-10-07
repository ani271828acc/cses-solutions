#include <bits/stdc++.h>

using namespace std;

int main()
{
     int n;
     cin>>n;
     n=n%4;// sequence repeats after 4
     if(n==1||n==2)
     cout<<"1";
     else
     cout<<"0";
    return 0;
}

