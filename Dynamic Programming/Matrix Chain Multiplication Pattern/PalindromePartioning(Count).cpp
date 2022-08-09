#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    bool isPalindrome(int i,int j,string &s){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
    int solve(int i,int j,string &str,vector<vector<int>> &dp){
        if(i >= j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(isPalindrome(i,j,str) == true){
            return 0;
        }

        int ans = INT_MAX;
        for(int k=i; k<j; k++){
            int temp = solve(i,k,str,dp) + solve(k+1,j,str,dp) + 1;
            ans = min(ans,temp);
        }
        return dp[i][j] = ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,str,dp);
    }
};
/*
Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.


Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
              are "a", "babbbab", "b", "ababa".
*/