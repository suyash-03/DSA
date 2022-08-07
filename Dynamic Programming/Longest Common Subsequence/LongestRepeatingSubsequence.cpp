#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	    int lrsUtil(int n,int m,string &x,string &y,vector<vector<int>> &dp){
	        if(n == 0 || m == 0){
	            return 0;
	        }
	        if(dp[n][m] != -1){
	            return dp[n][m];
	        }
	        if(x[n-1] == y[m-1] && n != m){
	            return dp[n][m] = 1+ lrsUtil(n-1,m-1,x,y,dp);
	        }else{
	            return dp[n][m] = max(lrsUtil(n-1,m,x,y,dp),lrsUtil(n,m-1,x,y,dp));
	        }
	    }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    string strCopy = str;
		    int n = str.size();
		    int m = n;
		    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
		    return lrsUtil(n,m,str,strCopy,dp);
		}

};

int main(){
    Solution s;
    int res = s.LongestRepeatingSubsequence("axxzxy");
    cout<<res;
    return 0;
}