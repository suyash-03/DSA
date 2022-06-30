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
    cout<<endl;
    return adjList;
}

bool isCyclicBFS(unordered_map<int,list<int>> &adjList, unordered_map<int,bool> &visited,int node){
    
    queue<int> q;
    unordered_map<int,int> parent;
    q.push(node);
    parent[node] = -1;
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        for(auto i:adjList[frontNode])
        {
            //Test Condition
            if(visited[i] == 1 && i != parent[frontNode] ){
                return true;
            }else if( !visited[i] ){
                q.push(i);
                visited[i] = 1;
                parent[i] = frontNode;
            }
        }
    }
    return false;
}


bool isGraphCyclic(unordered_map<int,list<int>> adjList,int vertex){
    unordered_map<int,bool> visited;
    bool result;
    for(int node = 0; node<vertex; node++){
        if( !visited[node] ){
            result = isCyclicBFS(adjList,visited,node);
        }
    }
    if(result == 1){
        cout<<"Graph is Cyclic \n";
    }else{
        cout<<"Graph is not Cyclic \n";
    }
    return result;
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
    isGraphCyclic(adjList,vertices);
    return 0;
}