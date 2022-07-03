#include<bits/stdc++.h>
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

vector<int> topologicalSort(unordered_map<int,list<int>> &adjList,int &vertices){
    vector<int> indegrees(vertices);
    for(auto i: adjList){
        for(auto j: i.second){
            indegrees[j]++;
        }
    }

    queue<int> q;
    for(int i=0; i<vertices; i++){
        if(indegrees[i] == 0) {
            q.push(i);
        } //i
    }

    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for(auto neighbour: adjList[front]){
            indegrees[neighbour]--;
            if(indegrees[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    return ans;
}



//Graph is directed
int main(){
    int vertices;
    int edges;
    vector<int> result;
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
    result = topologicalSort(adjList,vertices);
    for(auto i: result){
        cout<<i<<" ";
    }
    return 0;
}