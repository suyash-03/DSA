class Solution {
public:
    int lcs(int n,int m, string &word1,string &word2,vector<vector<int>> &dp){
        if(n == 0){
            return m;
        }
        if(m == 0){
            return n;
        }
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        if(word1[n-1] == word2[m-1]){
            return dp[n][m] = lcs(n-1,m-1,word1,word2,dp);
        }else{
            int add = lcs(n-1,m,word1,word2,dp);
            int del = lcs(n,m-1,word1,word2,dp);
            int rep = lcs(n-1,m-1,word1,word2,dp);
            return dp[n][m] = 1+min(add,min(del,rep));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int res = lcs(n,m,word1,word2,dp);
        return res;
    }
};
