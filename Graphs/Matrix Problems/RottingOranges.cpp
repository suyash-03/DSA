#include <vector>
#include <queue>
#include <iostream>
using namespace std;        
// This question is about finding the minimum time required to rot all oranges in a grid.
// The grid contains three types of cells: empty (0), fresh oranges (1), and rotten oranges (2).
// The rotten oranges spread their rot to adjacent fresh oranges in one minute.     
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        // Directions
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, -1, 0, 1};
        
        // Implement Multi Source BFS, after all rotten oranges are identified
        int ans = -1; 
        while(!q.empty()){
            int sz = q.size();
            ans++; // For the first loop iteration it will come to default
            for(int s = 0; s < sz; s++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k = 0; k < 4; k++){
                    int new_i = i + dr[k];
                    int new_j = j + dc[k];
                    if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == 1){
                        q.push({new_i, new_j});
                        grid[new_i][new_j] = 2;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ans == -1 ? 0 : ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    int result = sol.orangesRotting(grid);
    // Output the result
    cout << "Minimum time to rot all oranges: " << result << endl;
    return 0;
}   