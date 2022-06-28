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
        adjList[v].push_back(u);
    }
    
    return adjList;
}

//We are assuming graph components are not disconnected
void depthFirstSearch(unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,int node,vector<int> &result){

    result.push_back(node);
    visited[node] = 1;

    for(auto i: adjList[node]){
        if( !visited[i] ){
            depthFirstSearch(adjList,visited,i,result);
        }
    }
    
}

void dfs(unordered_map<int,list<int>> &adjList, int &vertices){
    unordered_map<int,bool> visited;
    vector<int> result;
    for(int node = 0; node<vertices; node++){
        depthFirstSearch(adjList,visited,node,result);
    }

    for(int i=0; i<result.size(); i++ ){
        cout<<result[i]<<",";
    }
}


//Graph is undirected
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
    printAdjacencyList(adjList);
    cout<<endl;
    dfs(adjList,vertices);
    return 0;
}