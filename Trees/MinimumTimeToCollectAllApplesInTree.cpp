#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

/*
LeetCode 1443: Minimum Time to Collect All Apples in a Tree

The tree is undirected, but we start DFS from node 0 and treat it as rooted at 0.
For every child subtree, there are only two useful possibilities:

1. The subtree has no apple.
   We should never enter that subtree, because every edge costs time and gives
   no benefit.

2. The subtree has at least one apple.
   We must cross the edge from parent to child once to enter that subtree, and
   once again to come back to the parent. That is why every useful child subtree
   adds exactly 2 seconds to the answer.

The DFS returns whether the current subtree contains an apple. The global ans
stores the total cost of all useful edges.
*/

class Solution {
public:
    int ans = 0;

    unordered_map<int, list<int>> createAdjList(vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adjList;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        return adjList;
    }

    bool dfs(int node, int parent, unordered_map<int, list<int>>& adjList, vector<bool>& hasApple) {
        // Start with whether the current node itself has an apple.
        bool has = hasApple[node];

        for (auto child : adjList[node]) {
            // Since the graph is undirected, skip the edge back to parent.
            if (child == parent) {
                continue;
            }

            // If this child subtree has any apple, we need to travel:
            // parent -> child and child -> parent, so add 2.
            if (dfs(child, node, adjList, hasApple)) {
                ans += 2;
                has = true;
            }
        }

        // Tell the parent whether this whole subtree contains an apple.
        return has;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, list<int>> adjList = createAdjList(edges);

        // Root the tree at 0. Any useful edge below this root contributes 2
        // because the route must come back to node 0.
        dfs(0, -1, adjList, hasApple);

        return ans;
    }
};
