#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int dfs(int i,int j,int m,int n,vector<vector<string>> &matrix,vector<vector<int>> &dp){
        if(i >= m || j >= n || i < 0 || j < 0 || matrix[i][j] == "0"){
            return -1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int a = 1 + dfs(i+1,j,m,n,matrix,dp);
        int b = 1 + dfs(i,j+1,m,n,matrix,dp);
        int c = 1 + dfs(i+1,j+1,m,n,matrix,dp);
        
        return dp[i][j] = min(a,min(b,c));
    }
    
    int maximalSquare(vector<vector<string>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxi = 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == "1"){
                    int res = 1+dfs(i,j,m,n,matrix,dp);
                    maxi = max(maxi,res);
                }
            }
        }
        return maxi*maxi;
        
    }
};


int main(){
    Solution s;
    vector<vector<string>> matrix = {{"1","0","1","0","0"},{"1","0","1","1","1"},{"1","1","1","1","1"},{"1","0","0","1","0"}};
    int res = s.maximalSquare(matrix);
    cout<<res<<endl;
    return 0;
}