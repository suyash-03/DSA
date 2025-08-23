#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
   public:
    void dfs(int i, int j, int n, int m, vector<vector<int>> &visited, vector<vector<char>> &mat) {
        if (i >= n || j >= m || i < 0 || j < 0 || mat[i][j] == 'X' || visited[i][j] == 1) {
            return;
        }
        visited[i][j] = 1 ;
        dfs(i + 1, j, n, m, visited, mat);
        dfs(i - 1, j, n, m, visited, mat);
        dfs(i, j + 1, n, m, visited, mat);
        dfs(i, j - 1, n, m, visited, mat);
    }
    vector<vector<char>> fill(vector<vector<char>> mat) {

        // Find Boundary 'O's and convert and do DFS on them to mark their
        // adjacent 'O' These marked 'O's can never be converted into 'X'
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Traverse First Row and Last Row
        for (int j = 0; j < m; j++) {
            if (!visited[0][j] && mat[0][j] == 'O') {
                dfs(0, j, n, m, visited, mat);
            }
            if (!visited[n - 1][j] && mat[n - 1][j] == 'O') {
                dfs(n - 1, j, n, m, visited, mat);
            }
        }

        // Traverse First and Last column
        for (int i = 0; i < n; i++) {
            if (!visited[i][0] && mat[i][0] == 'O') {
                dfs(i, 0, n, m, visited, mat);
            }
            if (!visited[i][m - 1] && mat[i][m - 1] == 'O') {
                dfs(i, m - 1, n, m, visited, mat);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> mat = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    vector<vector<char>> result = sol.fill(mat);
    for (const auto& row : result) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}