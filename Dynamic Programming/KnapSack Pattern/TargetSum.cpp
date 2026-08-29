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
        
        /*
            When you assign + and - signs to the elements in the array,
            you are essentially dividing the array into two separate groups (subsets):
            Subset 1 (S1): all numbers that get a + sign.
            Subset 2 (S2): all numbers that get a - sign.

            Based on the problem requirement:
            S1 - S2 = target

            Also, if you add both groups together (ignoring the signs), they form
            the total sum of the whole array:
            S1 + S2 = sumOfArray

            Adding both equations:
            (S1 - S2) + (S1 + S2) = target + sumOfArray
            2S1 = target + sumOfArray
            S1 = (target + sumOfArray) / 2

            So the problem reduces to counting subsets whose sum is exactly:
            (target + sumOfArray) / 2
        */

        int sumOfArray = accumulate(nums.begin(),nums.end(),0);
        int targetSum = (target+sumOfArray)/2;
        if( (target+sumOfArray) % 2 != 0 || sumOfArray < target || targetSum < 0) return 0;
        //Now we will find count of subsets with sum equals target Sum
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(abs(targetSum)+1,-1));
        return dfs(n,nums,targetSum,dp);
        
    }
};

/*
When you assign + and - signs to the elements in the array,
 you are essentially dividing the array into two separate groups (subsets):Subset 1 ($S_1$): All the numbers that get a + sign.Subset 2 ($S_2$): All the numbers that get a - sign.Based on the problem requirements, the sum of the positive group minus the sum of the negative group must equal your target.$$S_1 - S_2 = target$$We also know that if you add both groups together (ignoring the negative signs), they must equal the total sum of the array.$$S_1 + S_2 = sumOfArray$$Now, if you add those two algebraic equations together, the $S_2$ terms cancel out:$$(S_1 - S_2) + (S_1 + S_2) = target + sumOfArray$$$$2S_1 = target + sumOfArray$$$$S_1 = \frac{target + sumOfArray}{2}$$

*/


int main(){
    Solution s;
    vector<int> vec = {100};
    int res = s.findTargetSumWays(vec,-200);
    cout<<res;
    return 0;
}