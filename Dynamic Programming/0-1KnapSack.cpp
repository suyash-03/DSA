/*
Question:
Given two integer arrays val and wt of size N each which represent values and weights associated with N items respectively.
Also given an integer C which represents knapsack capacity.
Find out the maximum value subset of A such that sum of the weights of this subset is smaller than or equal to C

int dfs(int n,vector<int> &val,vector<int> &wt,int C,vector<vector<int>> &dp){
    
    if(n == 0 || C == 0){
        return dp[n][C] = 0;
    }
    if(dp[n][C] != -1){
        return dp[n][C];
    }
    if(wt[n-1] <= C){
        return dp[n][C] = max( val[n-1] + dfs(n-1,val,wt,C-wt[n-1],dp), dfs(n-1,val,wt,C,dp));
    }else{
        return dp[n][C] = dfs(n-1,val,wt,C,dp);
    }
}

int Solution::solve(vector<int> &val, vector<int> &wt, int C) {
    int n = val.size();
    vector<vector<int>> dp(n+1,vector<int>(C+1,-1));
    return dfs(n,val,wt,C,dp);
}

*/