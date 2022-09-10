#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTreesUtil(int n,vector<int> &dp){
        if(dp[n] != 0){
            return dp[n];
        }
        for(int i=1; i<=n; i++){
            dp[n] = dp[n] + (numTreesUtil(n-i,dp) * numTreesUtil(i-1,dp));
        }
        
        return dp[n];
    }
    
    int numTrees(int n) {
        if(n <= 1){
            return n;
        }
        vector<int> dp(n+1,0);
        dp[0] = dp[1] = 1;
        return numTreesUtil(n,dp);
    }
};
