#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;    

class Solution {
   public:
    void markIslands(vector<vector<int>> &grid, int i, int j, int m, int n, int bi, int bj, vector<pair<int,int>> &shape) {
        if (i >= n || i < 0 || j >= m || j < 0 || grid[i][j] != 1) {
            return;
        }
        grid[i][j] = 2;

        // store relative coordinate w.r.t base (bi, bj)
        shape.push_back({i - bi, j - bj});

        markIslands(grid, i + 1, j, m, n, bi, bj, shape);
        markIslands(grid, i - 1, j, m, n, bi, bj, shape);
        markIslands(grid, i, j + 1, m, n, bi, bj, shape);
        markIslands(grid, i, j - 1, m, n, bi, bj, shape);
    }

    int countDistinctIslands(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        set<vector<pair<int,int>>> distinctShapes;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    vector<pair<int,int>> shape;
                    markIslands(grid, i, j, m, n, i, j, shape);
                    distinctShapes.insert(shape);  // store normalized shape
                }
            }
        }
        return distinctShapes.size();
    }
};
int main() {
    Solution s;
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0}
    };
    int result = s.countDistinctIslands(grid);
    cout << "Number of distinct islands: " << result << endl;
    return 0;
}   