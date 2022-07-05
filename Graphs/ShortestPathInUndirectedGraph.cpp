#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
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

vector<int> shortestPathInUndirectedGraph(unordered_map<int,list<int>> &adjList,int source,int destination){
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    
    //bfs
    queue<int> q;
    q.push(source);
    visited[source] = 1;
    parent[source] = -1;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto i: adjList[front]){
            if(!visited[i]){
                visited[i] = 1;
                parent[i] = front;
                q.push(i);
            }

        }
    }

    //prepare shortest path
    vector<int> ans;
    int currentNode = destination;
    ans.push_back(currentNode);
    while(currentNode != source){
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
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
    vector<int> result = shortestPathInUndirectedGraph(adjList,1,8);
    for(auto i:result){
        cout<<i<<" ";
    }
    
    return 0;
}