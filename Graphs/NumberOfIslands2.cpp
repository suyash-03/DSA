#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
    Number of Islands II using Disjoint Set Union (DSU)

    Problem idea:
    - We are given a grid of size n x m.
    - Each operation adds a land cell at position (row, col).
    - After each addition, we must report how many connected components (islands) exist.

    DSU helps us efficiently group adjacent land cells:
    - each cell is treated as a node
    - if two neighboring cells are both land, we union them
    - the number of islands is tracked by decrementing whenever two islands merge
*/

class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n, 0);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int node) {
        if (node == parent[node]) {
            return node;
        }

        // Path compression: make every node point directly to its root
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int rootU = findUParent(u);
        int rootV = findUParent(v);

        if (rootU == rootV) {
            return;
        }

        // Attach smaller rank tree under bigger rank tree
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootV] < rank[rootU]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
};

class Solution {
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>>& A) {
        vector<int> ans;
        DSU dsu(n * m);
        unordered_map<int, bool> visited;

        int islandCount = 0;

        for (auto& cell : A) {
            int row = cell[0];
            int col = cell[1];
            int index = row * m + col;

            // If the cell was already added, the island count remains unchanged
            if (visited[index]) {
                ans.push_back(islandCount);
                continue;
            }

            // Add this new land cell as its own island
            visited[index] = true;
            islandCount++;

            // Explore 4-directional neighbors: up, right, down, left
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};

            for (int k = 0; k < 4; k++) {
                int newRow = row + dr[k];
                int newCol = col + dc[k];

                if (newRow < 0 || newCol < 0 || newRow >= n || newCol >= m) {
                    continue;
                }

                int neighborIndex = newRow * m + newCol;

                // Only merge if the neighboring cell was already added as land
                if (!visited[neighborIndex]) {
                    continue;
                }

                if (dsu.findUParent(index) != dsu.findUParent(neighborIndex)) {
                    islandCount--;
                    dsu.unionByRank(index, neighborIndex);
                }
            }

            ans.push_back(islandCount);
        }

        return ans;
    }
};

int main() {
    // Example:
    // A grid of size 3 x 4.
    // We add land cells one by one and track the number of islands after each addition.
    int n = 3;
    int m = 4;

    vector<vector<int>> operations = {
        {0, 0}, // 1 island
        {0, 1}, // still 1 island (adjacent to previous cell)
        {1, 0}, // still 1 island (connected to the same island)
        {2, 2}, // now 2 islands: top-left island + bottom-right island
        {2, 3}  // still 2 islands (adjacent to the new island)
    };

    Solution sol;
    vector<int> result = sol.numOfIslands(n, m, operations);

    std::cout << "Island count after each addition: ";
    for (int x : result) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Explanation of the example:
    // After {0,0} -> 1
    // After {0,1} -> 1 (same island)
    // After {1,0} -> 1 (same island)
    // After {2,2} -> 2
    // After {2,3} -> 2 (same island)

    return 0;
}