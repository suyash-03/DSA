#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>> adjL;

    void addEdge(int u,int v,bool direction){
        //direction = 0 -> undirected
        //direction = 1 -> directed

        //create an edge from u to v
        adjL[u].push_back(v);
        
        if(direction == 0){
            adjL[v].push_back(u);
        }
    }

    void printAdjList(){
         for(auto i:adjL){
            cout<<i.first<< "->";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
         }   
    }


};

int main(){
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edges"<<endl;
    cin>>m;

    Graph g;
    for(int i=0; i<m; i++){
        int u, v;
        //Inputing the edges 
        cin>>u>>v;
        //Creating an undirected graph
        g.addEdge(u,v,0);
    } 
    g.printAdjList();
    return 0;
}