#include <iostream>
#include <list>
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        DSU dsu(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j]){
                    dsu.unionByRank(i, j);
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(i == dsu.findUParent(i)){
                ans++;
            }
        }

        return ans;
    }
};

//DFS

class Solution {
public:
    unordered_map<int, list<int>> createAdjList(vector<vector<int>>& isConnected, int n){
        unordered_map<int, list<int>> adjList;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j]){
                    int u = i+1;
                    int v = j+1;

                    adjList[u].push_back(v);
                    adjList[v].push_back(u);
                }
            }
        }

        return adjList;
    }
    void dfs(int node, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited){
        visited[node] = true;
        for(auto i: adjList[node]){
            if(!visited[i]){
                dfs(i, adjList, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, list<int>> adjList = createAdjList(isConnected, n);
        unordered_map<int, bool> visited;
        int ans = 0;

        for(int node = 1; node <= n; node++){
            if(!visited[node]){
                ans++;
                dfs(node, adjList, visited);
            }
        }

        return ans;
    }
};