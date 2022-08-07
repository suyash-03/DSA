#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int util(int i,int j,int m,vector<vector<int>> &A,vector<vector<int>> &dp){
    if(i == m-1){
        return A[i][j];
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int a = A[i][j] + util(i+1,j,m,A,dp);
    int b = A[i][j] + util(i+1,j+1,m,A,dp);
    return dp[i][j] = max(a,b);
}
int solve(vector<vector<int> > &A) {
    int m = A.size();
    vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
    return util(0,0,m,A,dp);
}

int main(){
    vector<vector<int>> A = {{1},{2,3}};
    return solve(A);
}
