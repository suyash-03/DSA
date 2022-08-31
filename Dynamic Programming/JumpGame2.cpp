#include <bits/stdc++.h>
using namespace std;
class Solution {
public:  
    int jump(vector<int>& nums) {
        vector<long long> dp(size(nums), INT_MAX); 
        return solve(nums, dp, 0);
    }
    int solve(vector<int>& nums, vector<long long>& dp, int pos) {
        if(pos >= nums.size() - 1) return 0;    
        if(dp[pos] != INT_MAX){
            return dp[pos];
        }    
        for(int j = 1; j <= nums[pos]; j++){
            dp[pos] = min(0ll + dp[pos], 1ll + solve(nums, dp, pos + j));
        }
                    
        return dp[pos];
    }
};
