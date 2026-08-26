#include <bits/stdc++.h>
using namespace std;

class DSU{
    private:
        vector<int> rank;
        vector<int> parent;

    public:
        DSU(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1, 0);

            for(int i = 0; i < n+1; i++){
                parent[i] = i;
            }
        }

        int findUParent(int node){
            if(parent[node] == node){
                return node;
            }
            return parent[node] = findUParent(parent[node]);
        }

        void unionByRank(int u, int v){
            int pu = findUParent(u);
            int pv = findUParent(v);

            if(pu == pv) return;

            if(rank[pu] < rank[pv]){
                parent[pu] = pv;
            }else if(rank[pv] < rank[pu]){
                parent[pv] = pu;
            }else{
                parent[pv] = pu;
                rank[pu]++;
            }
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        DSU dsu(n);

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];

            if(dsu.findUParent(u) != dsu.findUParent(v)){
                dsu.unionByRank(u, v);
            }else{
                ans.clear();
                ans.push_back(u);
                ans.push_back(v);
            }
        }

        return ans;
    }
};

