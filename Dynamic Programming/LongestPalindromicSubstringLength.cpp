#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int util(int i,int j,string s,vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }
        if(i == j){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == s[j]){
            int lengthRemaining = j-i-1;
            if(lengthRemaining == util(i+1,j-1,s,dp)){
                return dp[i][j] = 2+lengthRemaining;
            }
        }
        return dp[i][j] = max(util(i+1,j,s,dp),util(i,j-1,s,dp));
    }
    int longestPalindromicSubstring(string s){
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return util(0,s.size()-1,s,dp);
    }
};

int main(){
    Solution sol;
    string s = "babad";
    int res = sol.longestPalindromicSubstring(s);
    cout<<res;
}