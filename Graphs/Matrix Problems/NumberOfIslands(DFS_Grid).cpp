//important
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void markCurrentIsland(vector<vector<string>> &grid,int i,int j,int rows,int cols){
        if(i >= rows || j >=cols || i<0 || j<0 || grid[i][j] != "1"){
            return;
        }
        //marking island as visited;
        grid[i][j] = "2";
        
        markCurrentIsland(grid,i+1,j,rows,cols);
        markCurrentIsland(grid,i,j+1,rows,cols);
        markCurrentIsland(grid,i-1,j,rows,cols);
        markCurrentIsland(grid,i,j-1,rows,cols);
    }
    
    int numIslands(vector<vector<string>>& grid) {
        int rows = grid.size();
        if(rows == 0) return 0;
        int cols = grid[0].size();
        
        //Iterate for all cells
        int numberOfIslands = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == "1"){
                    markCurrentIsland(grid,i,j,rows,cols);
                    numberOfIslands += 1;
                }
            }
        }
        
        return numberOfIslands;
    }
};
int main(){
    vector<vector<string>> grid = {
        {"1","1","1","1","0"},
        {"1","1","0","1","0"},
        {"1","1","0","0","0"},
        {"0","0","0","0","0"}
    };
    Solution s;
    int res = s.numIslands(grid);
    cout<<res;
    return 0;
}