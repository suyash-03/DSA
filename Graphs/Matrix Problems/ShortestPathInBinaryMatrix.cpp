#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
                    
        if(grid[0][0] == 1){
            return -1;
        }
        
        vector<pair<int,int>> directions = {
            {0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1}
        };
        
        grid[0][0] = 1;

        
        queue<vector<int>> q;
        q.push({0,0,1});
        
        while(!q.empty()){
            vector<int> temp = q.front();
            int x = temp[0];
            int y = temp[1];
            int len = temp[2];
            
            q.pop();
            
            if(x == m-1 && y == n-1){
                return len;
            }
            
            for(int i=0; i<directions.size(); i++){
                int newX = x + directions[i].first;
                int newY = y + directions[i].second;
                
                if( (newX >= 0) && (newX < m) && (newY >= 0) && (newY < n) && (grid[newX][newY] != 1)){
                    
                    grid[newX][newY] = 1;
                    q.push({newX,newY,len+1});
                }
            }
        }
        return -1;
    }
};
