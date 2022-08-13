#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Barely Passes on Leetcode
class Solution {
public:
    int dfs(int currIndex,int prevIndex,vector<int> &nums,vector<vector<int>> &dp){
        if(currIndex < 0){
            return 0;
        }
        if(dp[currIndex][prevIndex] != -1){
            return dp[currIndex][prevIndex];
        }        
        if(prevIndex == nums.size() || nums[currIndex] < nums[prevIndex]){
            return dp[currIndex][prevIndex] = max(1+dfs(currIndex-1,currIndex,nums,dp),dfs(currIndex-1,prevIndex,nums,dp));
        }else{
            return dp[currIndex][prevIndex] = dfs(currIndex-1,prevIndex,nums,dp);
        }
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return dfs(n-1,n,nums,dp);
    }
};

//nlogn tc using binary search
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }else{
                int index = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
};

