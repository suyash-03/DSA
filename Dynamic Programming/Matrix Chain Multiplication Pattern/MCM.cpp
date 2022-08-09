#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int solve(int arr[],int i,int j,vector<vector<int>> &dp){
        if(i >= j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int minVal = INT_MAX;
        for(int k = i; k < j ; k++){
            int tempAns = solve(arr,i,k,dp)+solve(arr,k+1,j,dp)+(arr[i-1]*arr[k]*arr[j]);
            minVal = min(tempAns,minVal);
        }
        return dp[i][j] = minVal;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
        return solve(arr,1,N-1,dp);
    }
};

int main(){
    Solution s;
    int arr[] = {10,30,5,60};
    int res = s.matrixMultiplication(4,arr);
    cout<<res<<endl;
}

/*

*/