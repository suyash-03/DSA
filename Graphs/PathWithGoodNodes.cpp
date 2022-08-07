#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int res;
void createAdjacencyList(vector<vector<int>> &B,unordered_map<int,list<int>> &adjList){
    for(int i=0; i<B.size(); i++){
        int u = B[i][0];
        int v = B[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void dfsUtil(int node,unordered_map<int,list<int>> &adjList,vector<int> &goodNodes,int count,int C,int parent){
    if(adjList[node].size() == 1){
        if(count <= C){
            res++;
        }
        return;
    }
    for(auto i:adjList[node]){
        if(i != parent){
            if(goodNodes[i] == 1){
                dfsUtil(i,adjList,goodNodes,count+1,C,node);
            }else{
                dfsUtil(i,adjList,goodNodes,count,C,node);
            }            
        }else{
            continue;
        }
    }
}

int solve(vector<int> &A, vector<vector<int> > &B, int C) {
    res = 0;
    unordered_map<int,list<int>> adjList;
    vector<int> goodNodes(A.size()+1,0);
    for(int i=0; i<A.size(); i++){
        goodNodes[i+1] = A[i];
    }
    createAdjacencyList(B,adjList);
    dfsUtil(1,adjList,goodNodes,goodNodes[1],C,-1);
    return res;
}


/*
Given a tree with N nodes labelled from 1 to N.

Each node is either good or bad denoted by binary array A of size N where if A[i] is 1 then ithnode is good else if A[i] is 
0 then ith node is bad.

Also the given tree is rooted at node 1 and you need to tell the number of root to leaf paths in the tree that contain not more than C good nodes.

NOTE:

Each edge in the tree is bi-directional

Input 1:

 A = [0, 1, 0, 1, 1, 1]
 B = [  [1, 2]
        [1, 5]
        [1, 6]
        [2, 3]
        [2, 4]
     ]
 C = 1

 Output 1:

 3

 Explanation 1:

 Path (1 - 2 - 3) and (1 - 5) and (1 - 6) are the paths which contain atmost C nodes.

*/