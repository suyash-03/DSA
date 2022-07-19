#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool dfs(int n,vector<int> &nums,int sum,vector<vector<int>> &dp){
        if(n <= 0){
            return 0;
        }
        if(sum == 0){
            return 1;
        }
        
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        
        if(nums[n-1] <= sum){
            return dp[n][sum] = ( dfs(n-1,nums,sum - nums[n-1],dp) || dfs(n-1,nums,sum,dp));
        }else{
            return dp[n][sum] = dfs(n-1,nums,sum,dp);
        }
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<nums.size(); i++){
            sum = sum + nums[i];
        }
        /* If the Sum of Input Array is odd it can never be partioned into two subsets of equal sum
         If the Sum is even then this problem changes to Subset Sum Problem with sum to search being
         equal to the sum of the input array /2 
         */
        if(sum % 2 == 1){
            return false;
        }else{
            vector<vector<int>> dp(n+1,vector<int>((sum/2)+1,-1));
            return dfs(n,nums,sum/2,dp);
        }
    }
};


int main(){
    vector<int> temp = {1,5,11,5};
    Solution s;
    bool result = s.canPartition(temp);
    cout<<result;
    return 0;
}