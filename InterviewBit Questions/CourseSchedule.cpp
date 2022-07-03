// Topological Sort , AdjList 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int,list<int>> adjList;
    unordered_map<int,bool> visited;
    stack<int> s;
    vector<int> result;
    void createAdjacencyList(vector<vector<int>> &prerequisites){
        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            
            adjList[u].push_back(v);
        }
    }
    
    void topologicalSortUtil(int node){
        visited[node] = 1;
        for(auto i: adjList[node]){
            if(!visited[i]){
                topologicalSortUtil(i);
            }
        }
        s.push(node);
    }
    
    void topologicalSort(int vertices){
        for(int node=0; node<vertices; node++){
            if(!visited[node]){
                topologicalSortUtil(node);
            }
        }
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        createAdjacencyList(prerequisites);
        topologicalSort(numCourses);
        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        unordered_map<int,bool> hasVisited;
        for(int i=0 ; i<result.size(); i++){
            hasVisited[result[i]] = 1;
            for(auto j : adjList[result[i]]){
                if(hasVisited[j] == 1) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s1;
    vector<vector<int>> toPass;
    vector<int> temp;
    vector<int> temp2;
    temp.push_back(1);
    temp.push_back(0);
    
    temp2.push_back(0);
    temp2.push_back(1);
    toPass.push_back(temp);
    toPass.push_back(temp2);
    bool result = s1.canFinish(2,toPass);
    cout<<result;
    return 0;
}