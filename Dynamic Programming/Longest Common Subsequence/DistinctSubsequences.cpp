#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lcs(string &s,string &t,int m,int n,vector<vector<int>> &dp){
        //We can select one empty string if both the strings are empty
        if(m == 0 && n == 0){
            return 1;
        }
        //is t is empty and s is not empty ( we can choose empty substring from a non empty string )
        if(n == 0 && m != 0){
            return 1;
        }
        //if t is not empty but s is empty (base case which returns 0 )
        if(m == 0 && n != 0){
            return 0;
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        if(s[m-1] == t[n-1]){
            return dp[m][n] = (lcs(s,t,m-1,n-1,dp)+lcs(s,t,m-1,n,dp));
        }else{
            return dp[m][n] = lcs(s,t,m-1,n,dp);
        }
        
    }
    
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return lcs(s,t,m,n,dp);
    }
};
