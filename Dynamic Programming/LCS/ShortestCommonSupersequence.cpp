#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int longestCommonSubsequenceUtil(string &text1,string &text2,int n,int m,vector<vector<int>> &dp){
        if(n == 0 || m == 0){
            return 0;
        }
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        if(text1[n-1] == text2[m-1]){
            return dp[n][m] = (1 + longestCommonSubsequenceUtil(text1,text2,n-1,m-1,dp));
        }else{
            return dp[n][m] = 
                max(longestCommonSubsequenceUtil(text1,text2,n-1,m,dp),longestCommonSubsequenceUtil(text1,text2,n,m-1,dp));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return longestCommonSubsequenceUtil(text1,text2,n,m,dp);
    }

    
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        string temp = X + Y;
        int lengthOfLCS = longestCommonSubsequence(X,Y);
        cout<<"Length of Longest Common Subsequence is: "<<lengthOfLCS<<endl;
        return (temp.size() - lengthOfLCS);
    }
};

int main(){
    Solution s;
    string X = "AVnQIELxFb"; int n = X.size();
    string Y = "TEpRbSvi"; int m = Y.size();
    int res = s.shortestCommonSupersequence(X,Y,n,m);
    cout<<"Length of Shortest Common Supersequence is: "<<res<<endl;
    return 0;
}