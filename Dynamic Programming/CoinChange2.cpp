// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
#include<utility>
using namespace std;

class Solution {
public:
    int dfs(int n,vector<int> &coins,int amount,vector<vector<int>> &dp){
        if(amount == 0){
            return dp[n][amount] = 0;
        }
        if( n == 0 && amount != 0){
            return dp[n][amount] = INT_MAX;
        }
        if(dp[n][amount] != -1){
            return dp[n][amount];
        }
        
        if(coins[n-1] <= amount){
            return dp[n][amount] = 
                min( 1ll + dfs(n,coins,amount - coins[n-1],dp) , dfs(n-1,coins,amount,dp) + 0ll );
        }
        else return dp[n][amount] = dfs(n-1,coins,amount,dp);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int res =  dfs(n,coins,amount,dp);
        if(res == INT_MAX){
            return -1;
        }else{
            return res;
        }
    }
};

int main() {
    Solution s;
    vector<int> coins = {1,2};
    int ans = s.coinChange(coins,15);
    cout<<"Answer: "<<ans;
    return 0;
}