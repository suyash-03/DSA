#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
   public:
    int util(int n, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp) {
        if (n <= 0) {
            return 0;
        }

        if(dp[n][j] != -1){
            return dp[n][j];
        }

        int running = 0;
        if (j != 1) {
            running = matrix[n - 1][0] + util(n - 1, 1, matrix, dp);
        }

        int stealth = 0;
        if(j != 2){
            stealth = matrix[n-1][1] + util(n-1, 2, matrix, dp);
        }

        int fighting = 0;
        if(j != 3){
            fighting = matrix[n-1][2] + util(n-1,3,matrix, dp);
        }

        return dp[n][j] = max(running, max(stealth, fighting));
    }
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n+1, vector<int>(4, -1));
        return util(n , 0, matrix, dp);
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };
    cout << sol.ninjaTraining(matrix) << endl;
    return 0;
}

// In this quest, you need to help the ninja maximize his training points by choosing the best training strategy.   
/*  A ninja has planned a n-day training schedule. 
    Each day he has to perform one of three activities - running, stealth training, or fighting practice.
    The same activity cannot be done on two consecutive days and the ninja earns a specific number of merit points, based on the activity and the given day.
    Given a n x 3-sized matrix, where matrix[i][0], matrix[i][1], and matrix[i][2], represent the merit points associated with running, stealth and fighting practice, on the (i+1)th day respectively.
    Return the maximum possible merit points that the ninja can earn.
*/