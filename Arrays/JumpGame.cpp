#include<bits/stdc++.h>
using namespace std;

class Solution {
     public:
     bool canJump(vector<int>& nums) {
         int goal = nums.size()-1;
         for(int i=nums.size()-1; i>=0; i--){
             if(i + nums[i] >= goal){
                 goal = i;
             }
         }
         if(goal == 0) return true;
         else return false;
     }
};
//DP Solution
class Solution2 {
public:
    bool canJumpUtil(int index,vector<int> &nums,vector<int> &dp){
        if(index >= nums.size()-1){
            return true;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        bool ans = false;
        for(int j = 1; j <= nums[index]; j++){
            ans = canJumpUtil(index+j,nums,dp);
            if(ans) break;
        }

        return dp[index] = ans;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return canJumpUtil(0,nums,dp);
    }
};
