#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int util(int n, vector<int> &points, vector<int> &dp){
        if(n <= 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int take = points[n-1] + util(n-2, points,dp);
        int notTake = util(n-1, points,dp);

        return dp[n] = max(take, notTake);
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxE = *max_element(nums.begin(), nums.end());

        vector<int> points(maxE+1,0);
        // Deal with Sum of Points rather than individual elements, maximum value you can get with each number
        for(int i = 0; i < nums.size(); i++){
            points[nums[i]] += nums[i];
        }
        int n = points.size();
        vector<int> dp(n+1,-1);
        return util(n, points, dp);
    }
};

int main(){
    Solution s;
    vector<int> v = {3,4,2};
    int res = s.deleteAndEarn(v);
    cout<<res;
}