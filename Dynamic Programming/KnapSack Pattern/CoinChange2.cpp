// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
#include<utility>
using namespace std;

class Solution {
public:
    int dfs(int n, vector<int> &coins,int amount,vector<vector<int>> &dp){
        if(n <= 0 && amount != 0){
            return dp[n][amount] = 0;
        }
        if(amount == 0){
            return dp[n][amount] = 1;
        }
        if(dp[n][amount] != -1){
            return dp[n][amount];
        }
        if(coins[n-1] <= amount){
            return dp[n][amount] = (dfs(n,coins,amount-coins[n-1],dp)+dfs(n-1,coins,amount,dp));
        }else{
            return dp[n][amount] = dfs(n-1,coins,amount,dp);
        }
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return dfs(n,coins,amount,dp);
    }
};

int main() {
    Solution s;
    vector<int> coins = {1,2};
    int ans = s.change(15,coins);
    cout<<"Answer: "<<ans;
    return 0;
}
