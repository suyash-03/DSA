// Topological Sort , AdjList 
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <list>  
using namespace std;

// Problem: Course Schedule
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
// Basically we are checking if the graph is cyclic or not. If it is cyclic then we cannot finish all the courses. If it is acyclic then we can finish all the courses.
class Solution {
public:
    unordered_map<int, list<int>> createAdjList(vector<vector<int>> &prerequisites){
        unordered_map<int,list<int>> adjList;
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[u].push_back(v);
        }

        return adjList;
    }
    bool isCyclic(int node, unordered_map<int,list<int>> &adjList, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited){
        visited[node] = true;
        dfsVisited[node] = true;
        for(auto i: adjList[node]){
            if(!visited[i]){
                if(isCyclic(i, adjList, visited, dfsVisited)) return true;
            }else if(dfsVisited[i]){
                return true;
            }
        }

        dfsVisited[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;
        unordered_map<int, list<int>> adjList = createAdjList(prerequisites);

        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(isCyclic(i, adjList, visited, dfsVisited)) return false;
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