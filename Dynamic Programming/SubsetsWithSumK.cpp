#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution{
	public:
	int dfs(int n,int arr[],int sum,vector<vector<int>> &dp){
	    if( n == 0 && sum != 0){
	        return 0;
	    }
	    if(sum == 0){
	        return 1;
	    }
	    if(dp[n][sum] != -1){
	        return dp[n][sum];
	    }
	    
	    
	    if(arr[n-1] <= sum){
	        return dp[n][sum] = (dfs(n-1,arr,sum-arr[n-1],dp) + dfs(n-1,arr,sum,dp));
	    }else{
	        return dp[n][sum] = (dfs(n-1,arr,sum,dp));
	    }
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
	    return dfs(n,arr,sum,dp);
	}
};


int main(){
    Solution s;
    int arr[] = {1,2,3,4,5};
    int n = 5;
    int res = s.perfectSum(arr,n,10);
    cout<<res<<endl;
    return 0;
}