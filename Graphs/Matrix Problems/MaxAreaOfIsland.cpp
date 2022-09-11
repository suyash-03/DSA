#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int i,int j,int m,int n,vector<vector<int>> &grid){
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0){
            return -1;
        }
        grid[i][j] = 0;
        
        
        int a = 1 + dfs(i+1,j,m,n,grid);
        int b = 1 + dfs(i-1,j,m,n,grid);
        int c = 1 + dfs(i,j+1,m,n,grid);
        int d = 1 + dfs(i,j-1,m,n,grid);
        
        return (a+b+c+d);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int res = 1+dfs(i,j,m,n,grid);
                    maxArea = max(maxArea,res);
                }
            }
        }
        return maxArea;
    }
};
