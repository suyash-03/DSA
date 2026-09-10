// Problem: Pacific Atlantic Water Flow
// Given an m x n matrix of non-negative integers representing the
// height of each cell, find the list of grid coordinates where water
// can flow to both the Pacific and Atlantic ocean.
// Water can flow from a cell to another one with height less than or
// equal to the current cell in the four directions (up, down, left, right).
// The Pacific touches the left and top edges of the matrix, and the
// Atlantic touches the right and bottom edges.
//
// Approach: perform DFS/BFS from each ocean's boundary to mark cells
// reachable by that ocean; the intersection of both reachable sets
// gives the required coordinates.

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<int>> &heights, vector<vector<int>> &visited){
        if(i >= m || j >= n || i < 0 || j < 0 || visited[i][j]) {
            return;
        }
        
        visited[i][j] = true;

        // Down
        if(i + 1 < m &&
           heights[i + 1][j] >= heights[i][j]) {
            dfs(i + 1, j, m, n, heights, visited);
        }

        // Up
        if(i - 1 >= 0 &&
           heights[i - 1][j] >= heights[i][j]) {
            dfs(i - 1, j, m, n, heights, visited);
        }

        // Right
        if(j + 1 < n &&
           heights[i][j + 1] >= heights[i][j]) {
            dfs(i, j + 1, m, n, heights, visited);
        }

        // Left
        if(j - 1 >= 0 &&
           heights[i][j - 1] >= heights[i][j]) {
            dfs(i, j - 1, m, n, heights, visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        //Pacific Boundary
        vector<vector<int>> pacificVisited(m+1, vector<int>(n+1, 0));
        for(int i = 0; i < m; i++){
            dfs(i, 0, m, n, heights, pacificVisited);
        }
        for(int i = 0; i < n; i++){
            dfs(0, i, m, n, heights, pacificVisited);
        }


        //Atlantic Boundary
        vector<vector<int>> atlanticVisited(m+1, vector<int>(n+1, 0));
        for(int i = 0; i < m; i++){
            dfs(i, n-1, m, n, heights, atlanticVisited);
            
        }
        for(int i = 0; i < n; i++){
            dfs(m-1, i, m, n, heights, atlanticVisited);
        }

        vector<vector<int>> ans;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacificVisited[i][j] && atlanticVisited[i][j]){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};