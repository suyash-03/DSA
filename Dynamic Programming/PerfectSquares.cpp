class Solution {
public:
    int numSquaresUtil(int n,vector<int> &dp){
        if(n <= 3){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int ans = n;
        for(int i=1; i*i <= n; i++){
            ans = min(ans,1+numSquaresUtil(n-i*i,dp));
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return numSquaresUtil(n,dp);
    }
};
