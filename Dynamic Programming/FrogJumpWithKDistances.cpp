#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int frogJumpUtil(int index, vector<int>& heights, int k, vector<int> &dp) {
        if (index >= heights.size() - 1) {
            return 0; 
        }

        if(dp[index] != -1){
            return dp[index];
        }
        int mJump = INT_MAX;

        for (int j = 1; j <= k; j++) {
            if (index + j < heights.size()) {
                int jump = frogJumpUtil(index + j, heights, k,dp) + abs(heights[index] - heights[index + j]);
                mJump = min(mJump, jump);
            }
        }
        return dp[index] = mJump;
    }

    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n+1, -1);
        return frogJumpUtil(0, heights, k,dp);
    }
};

int main(){
    Solution sol;
    vector<int> heights = {10, 30, 40, 50, 20};
    int k = 2;
    cout << sol.frogJump(heights, k) << endl;
    return 0;
}
