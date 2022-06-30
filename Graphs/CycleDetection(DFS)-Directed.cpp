#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

void printAdjacencyList(unordered_map<int,list<int>> adjList){
    unordered_map<int,list<int>>::iterator ptr;
    for(ptr = adjList.begin(); ptr != adjList.end(); ptr++){
        cout<<ptr->first<<"->";
        list<int>::iterator ptr2;
        for(ptr2 = (ptr->second).begin(); ptr2 != (ptr->second).end(); ptr2++){
            cout<<*ptr2<<",";
        }cout<<endl;
    }
}

unordered_map<int,list<int>> createAdjacencyList(vector<pair<int,int>> edgesList){
    unordered_map<int,list<int>> adjList;
    for(int i=0; i<edgesList.size(); i++){
        int u = edgesList[i].first;
        int v = edgesList[i].second;

        adjList[u].push_back(v); 
    }
    cout<<endl;
    return adjList;
}

bool checkCycleDFSUtil(unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsVisited,int node){
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto i: adjList[node]){
        if(!visited[i]){
            bool result = checkCycleDFSUtil(adjList,visited,dfsVisited,i);
            if(result == true) return true;
        }else if(dfsVisited[i] == true){
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

void checkCycleDFS(unordered_map<int,list<int>> &adjList,int vertices){
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;
    bool result = false;
    for(int node=0; node<vertices; node++){
        if(!visited[node]){
            result = checkCycleDFSUtil(adjList,visited,dfsVisited,node);
        }
    }
    if(result == true){
        cout<<"There is a Cycle present in the directed graph \n";
    }else{
        cout<<"There is no Cycle present in the directed graph \n";
    }
}



//Graph is directed
int main(){
    int vertices;
    int edges;
    vector<pair<int,int>> edgesList;
    cout<<"Enter the number of vertices\n";
    cin>>vertices;
    cout<<"Enter the number of Edges\n";
    cin>>edges;
    for(int i=0; i<edges; i++){
        pair<int,int> p;
        int u,v;
        cin>>u>>v;
        p.first = u;
        p.second = v;
        edgesList.push_back(p);
    }
    unordered_map<int,list<int>> adjList = createAdjacencyList(edgesList);
    checkCycleDFS(adjList,vertices);

    return 0;
}