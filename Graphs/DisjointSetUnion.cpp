#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

/*
    Disjoint Set Union (DSU) / Union-Find
    ------------------------------------
    Used to manage dynamic connectivity problems efficiently.

    Main operations:
    1. find(x) -> returns the representative/root of the set containing x
    2. union(x, y) -> merges two sets into one

    Optimizations used:
    - Path Compression: makes tree shallow so future finds become O(alpha(n))
    - Union by Rank / Union by Size: keeps the tree balanced and reduces height

    Typical use cases:
    - Detecting cycle in undirected graph
    - Connected components
    - Kruskal's algorithm for MST
    - Grouping elements into disjoint sets
*/

class DisjointSet {
public:
    vector<int> rank;   // Rank of each node (used in unionByRank)
    vector<int> parent; // Parent of each node
    vector<int> size;   // Size of each set (used in unionBySize)

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i; // Initially every node is its own parent
        }
    }

    // Finds the representative of the set containing 'node'
    // with path compression optimization.
    int findUParent(int node) {
        if (node == parent[node]) {
            return node;
        }

        // Compress the path: make every node point directly to the root.
        return parent[node] = findUParent(parent[node]);
    }

    // Returns true if u and v are in the same set, else false.
    bool find(int u, int v) {
        return findUParent(u) == findUParent(v);
    }

    // Union by Rank:
    // Attach the root with smaller rank under the root with larger rank.
    void unionByRank(int u, int v) {
        int pu = findUParent(u);
        int pv = findUParent(v);

        if (pu == pv) return; // Already in same set

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            // Same rank -> attach one under the other and increase rank.
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    // Union by Size:
    // Attach smaller set under larger set to keep tree shallow.
    void unionBySize(int u, int v) {
        int pu = findUParent(u);
        int pv = findUParent(v);

        if (pu == pv) return; // Already connected

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

/*
    Example:
    --------
    Suppose we have 6 elements: 0, 1, 2, 3, 4, 5
    We connect some pairs:
      (1, 2), (2, 3), (4, 5)

    After these unions, the sets are:
      {1, 2, 3} and {4, 5}

    Then, find(1, 3) == true
          find(1, 4) == false
*/

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 5;
    DisjointSet ds(n);

    // Union some elements
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);

    // Check connections
    std::cout << "Is 1 connected to 3? " << ds.find(1, 3) << "\n";
    std::cout << "Is 1 connected to 4? " << ds.find(1, 4) << "\n";

    // Example with unionBySize
    DisjointSet ds2(7);
    ds2.unionBySize(0, 1);
    ds2.unionBySize(1, 2);
    ds2.unionBySize(3, 4);
    ds2.unionBySize(5, 6);

    std::cout << "Is 0 connected to 2? " << ds2.find(0, 2) << "\n";
    std::cout << "Is 2 connected to 5? " << ds2.find(2, 5) << "\n";

    return 0;
}

/*
    Time Complexity:
    -----------------
    - find() : almost O(1) amortized due to path compression
    - union() : almost O(1) amortized
    - Total: very efficient for many union/find operations

    Space Complexity:
    -----------------
    O(n) for parent, size/rank arrays
*/
