#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lcs(string &text1,string &text2,int n,int m,vector<vector<int>> &dp){
        if(n <= 0 || m <= 0){
            return 0;
        }
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        if(text1[n-1] == text2[m-1]){
            return dp[n][m] = (1 + lcs(text1,text2,n-1,m-1,dp));
        }else{
            return dp[n][m] = max(lcs(text1,text2,n,m-1,dp),lcs(text1,text2,n-1,m,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        string temp = s;
        reverse(temp.begin(),temp.end());
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int res = lcs(s,temp,n,n,dp);
        return res;
    }
};

int main(){
    Solution s;
    int res = s.longestPalindromeSubseq("agbcba");
    cout<<res;
}