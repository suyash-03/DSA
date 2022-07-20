#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int dfs(int n,vector<int> &nums,int targetSum,vector<vector<int>> &dp){
        if(n == 0 && targetSum != 0){
            return 0;
        }
        if(n == 0 && targetSum == 0){
            return 1;
        }
        if(dp[n][targetSum] != -1){
            return dp[n][targetSum];
        }
        if(nums[n-1] <= targetSum){
            return dp[n][targetSum] = (dfs(n-1,nums,targetSum - nums[n-1],dp) + dfs(n-1,nums,targetSum,dp));
        }else{
            return dp[n][targetSum] = dfs(n-1,nums,targetSum,dp);
        }
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sumOfArray = accumulate(nums.begin(),nums.end(),0);
        int targetSum = (target+sumOfArray)/2;
        if( (target+sumOfArray) % 2 != 0 || sumOfArray < target || targetSum < 0) return 0;
        //Now we will find count of subsets with sum equals target Sum
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(abs(targetSum)+1,-1));
        return dfs(n,nums,targetSum,dp);
        
    }
};


int main(){
    Solution s;
    vector<int> vec = {100};
    int res = s.findTargetSumWays(vec,-200);
    cout<<res;
    return 0;
}