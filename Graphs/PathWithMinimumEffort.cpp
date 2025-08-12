#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0,0}});
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == m-1) return diff;
            for(int i = 0; i < 4; i++){
                int newR = row + dr[i];
                int newC = col + dc[i];
                if(newR >= 0 && newC >= 0 && newR < n && newC < m){
                    int newEffort = max(diff, abs(heights[newR][newC] - heights[row][col]));
                    if(newEffort < dist[newR][newC]){
                        dist[newR][newC] = newEffort;
                        pq.push({newEffort, {newR, newC}});
                    } 
                }
            }
        }
        return 0;
    }
};
// Minimum Effort Path Example
// Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 2
// Explanation: The path with minimum effort is highlighted in red, and the maximum difference in heights
// along this path is 2 (between 1 and 3, and between 2 and 5).
// The path is: (0,0) -> (0,1)  -> (1,1) -> (2,1) -> (2,2).
// Modified Dijkstra's algorithm is used to find the minimum effort path in a grid. 
int main() {
    Solution s;
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };
    int result = s.minimumEffortPath(heights);
    cout << "Minimum Effort Path: " << result << endl; // Output: 2
    return 0;
}