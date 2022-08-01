#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Recursive

class Solution {
public:
    int count = 0;
    void countWays(int i,int j,int m,int n){
        if(i == m-1 && j == n-1){
            count++;
            return;
        }
        if(i > m-1 || j > n-1){
            return;
        }
        
        countWays(i+1,j,m,n);
        countWays(i,j+1,m,n);
        
    }
    int uniquePaths(int m, int n) {
        countWays(0,0,m,n);
        return count;
    }
};

// Recursive + Memoisation = Top Down DP

class Solution {
public:
    int countWays(int i,int j,int m,int n,vector<vector<int>> &dp){
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(i > m-1 || j > n-1){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int b = dp[i][j] = countWays(i+1,j,m,n,dp);
        int r = dp[i][j] = countWays(i,j+1,m,n,dp);
        return dp[i][j] = (b+r);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return countWays(0,0,m,n,dp);
    }
};