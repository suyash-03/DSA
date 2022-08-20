#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int i,int j,int m,int n,int val,vector<vector<int>> &matrix,vector<vector<int>> &dp){
        if(i >= m || i < 0 || j >= n || j < 0 || matrix[i][j] <= val){
            return 0;
        }
        int a,b,c,d=1;
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        a = 1+dfs(i+1,j,m,n,matrix[i][j],matrix,dp);
        b = 1+dfs(i-1,j,m,n,matrix[i][j],matrix,dp);
        c = 1+dfs(i,j+1,m,n,matrix[i][j],matrix,dp);
        d = 1+dfs(i,j-1,m,n,matrix[i][j],matrix,dp);
    
        
        priority_queue<int> pq;
        pq.push(a); pq.push(b); pq.push(c); pq.push(d);
        return dp[i][j] = pq.top();
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 1;
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                res = max(res,dfs(i,j,m,n,-1,matrix,dp));
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
    int res = s.longestIncreasingPath(matrix);
    cout<<res;
}