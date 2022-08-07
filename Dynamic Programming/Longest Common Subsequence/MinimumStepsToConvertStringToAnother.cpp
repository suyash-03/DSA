//Find the minimum number of steps (Insertions and/or Deletions) to convert String A to String B

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lcs(string &word1,string &word2,int n,int m,vector<vector<int>> &dp){
        if(n <= 0 || m <= 0){
            return 0;
        }
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        if(word1[n-1] == word2[m-1]){
            return dp[n][m] = (1 + lcs(word1,word2,n-1,m-1,dp));
        }else{
            return dp[n][m] = max(lcs(word1,word2,n,m-1,dp),lcs(word1,word2,n-1,m,dp));
        }
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int lengthOfLCS = lcs(word1,word2,n,m,dp);
        int numDeletions = n - lengthOfLCS;
        int numAdditions = m - lengthOfLCS;
        return (numDeletions + numAdditions);
    }
};
