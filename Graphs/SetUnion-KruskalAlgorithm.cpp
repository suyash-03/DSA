#include<iostream>
#include<bits/stdc++.h>
using namespace std;

static bool cmp(vector<int> &a,vector<int> &b){
    return a[2] < b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n){
    for(int i=0; i<n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node){
    if(parent[node] = node){
        return node;
    }
    //Path Compression Logic
    return parent[node] = findParent(parent,parent[node]);
}

void unionSet(int u,int v,vector<int> &parent,vector<int> &rank){
    u = findParent(parent,u);
    v = findParent(parent,v);

    if(rank[u] < rank[v]){
        parent[u] = v;
    }else if(rank[v] < rank[u]){
        parent[v] = u;
    }else{
        parent[v] = u;
        rank[u]++;
    }

 }
// Time Complexity = O(mlogm), 
// We have to return the total weight of minimum spanning tree
int minimumSpanningTree(vector<vector<int>> &edges,int n){
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent,rank,n);
    int minWeight;
    for(int i=0; i<edges.size(); i++){
        int u = findParent(parent,edges[i][0]);
        int v = findParent(parent,edges[i][1]);
        int wt = edges[i][2];
        if(u != v){
            minWeight += wt;
            unionSet(u,v,parent,rank); 
        }
    }
    return minWeight;
    
}

int main(){
    vector<vector<int>> edges = {{1,2,2},{1,4,1},{1,5,4},{4,5,5},{4,3,5},{2,4,3},{2,3,3},{2,6,7},{3,6,8}};
    int res = minimumSpanningTree(edges,6);
    cout<<res;
    return 0;
}