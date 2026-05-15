#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;

/*
    Topological Sort using DFS

    Works only for a directed acyclic graph (DAG).

    Input:
    vertices edges
    u1 v1
    u2 v2
    ...

    Each edge u v means u -> v.
*/

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

bool topologicalSortUtil(unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsVisited,stack<int> &s,int node){
    visited[node] = 1;
    dfsVisited[node] = 1;

    for(auto i:adjList[node]){
        if( !visited[i] ){
            bool isPossible = topologicalSortUtil(adjList,visited,dfsVisited,s,i);
            if(!isPossible){
                return false;
            }
        }else if(dfsVisited[i]){
            return false;
        }
    }

    dfsVisited[node] = 0;
    
    //Main Part of DFS Topological Sort
    s.push(node);
    return true;
}

//If TLE use vector<int> for visited
void topologicalSort(unordered_map<int,list<int>> adjList,int vertices){
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;
    vector<int> result;
    stack<int> s;
    for(int node=0; node<vertices; node++){
        if(!visited[node]){
            bool isPossible = topologicalSortUtil(adjList,visited,dfsVisited,s,node);
            if(!isPossible){
                cout<<"Topological sort is not possible because the directed graph contains a cycle\n";
                return;
            }
        }
    }
    while(!s.empty()){
        result.push_back(s.top());
        s.pop();
    }
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";   
    }
}


//Graph is directed
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

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
    topologicalSort(adjList,vertices);
    return 0;
}
