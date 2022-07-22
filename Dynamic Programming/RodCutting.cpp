#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int dfs(int price[],int length[],int maxLength,int n,vector<vector<int>> &dp){
        if(n == 0 || maxLength == 0){
            return 0;
        }
        if(dp[n][maxLength] != -1){
            return dp[n][maxLength];
        }
        if(length[n-1] <= maxLength){
            return dp[n][maxLength]
            = max(price[n-1] + dfs(price,length,maxLength-length[n-1],n,dp),dfs(price,length,maxLength,n-1,dp));
        }else{
            return dp[n][maxLength] = dfs(price,length,maxLength,n-1,dp);
        }
        
    }
    
    int cutRod(int price[], int n) {
        int length[n];
        for(int i=0; i<n; i++){
            length[i] = i+1;
        }
        int maxLength = n;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return dfs(price,length,n,maxLength,dp);
    }
};

int main(){
    Solution s;
    int price[] = {1,5,8,9,10,17,17,20};
    int res = s.cutRod(price,8);
    cout<<res<<endl;
}