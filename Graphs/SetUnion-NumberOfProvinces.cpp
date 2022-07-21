#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count = 0;
    void setVectors(vector<int> &parent,vector<int> &rank,int n){
        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int findParent(int node, vector<int> &parent){
        cout<<parent[node]<<endl;
        if(parent[node] == node){
            return node;
        }
        //path compression logic
        return parent[node] = findParent(parent[node],parent);
        
    }
    
    void unionSet(int u,int v,vector<int> &parent, vector<int> &rank){
        u = findParent(u,parent);
        v = findParent(v,parent);
        if(u != v){
            count++;
            if(rank[u] < rank[v]){
                parent[u] = v;
            }else if(rank[v] < rank[u]){
                parent[v] = u;
            }else{
                parent[v] = u;
                rank[u]++;
            }            
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size() + 1;
        vector<int> parent(n);
        vector<int> rank(n);
        setVectors(parent,rank,n);
        
        for(int i=0; i<isConnected.size(); i++){
            for(int j=0; j<isConnected[0].size(); j++){
                if(isConnected[i][j] == 1 && i != j){
                    int u = i+1;
                    int v = j+1;
                    unionSet(u,v,parent,rank);
                }
            }
        }
        return (isConnected.size()-count);
        
    }
};

int main(){
    Solution s;
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    int res = s.findCircleNum(isConnected);
    cout<<"The value of count is: " <<s.count<<endl;
    cout<<res; 
    return 0;
}