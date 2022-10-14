/* Q. There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner. */


#include<bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
    int mat[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0) mat[i][j]=1;
            else mat[i][j]=mat[i-1][j]+mat[i][j-1];
        }
    }
    return mat[m-1][n-1];
}

int main(){
    int m,n;
    cin >> m >> n;
    cout << uniquePaths(m,n);
    
    return 0;
}

// Time Complexity : O(m*n)
// Space Complexity : O(m*n)
