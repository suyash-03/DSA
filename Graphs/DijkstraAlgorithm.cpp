#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//O(Elogv)
vector<int> dijsktra(vector<vector<int>> &edges,int vertices,int noOfEdges,int source){
    
    //create adjancency list
    unordered_map<int,list<pair<int,int>>> adjList;
    for(int i=0; i<noOfEdges; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }

    vector<int> dist(vertices,INT_MAX);
    set<pair<int,int>> st;

    dist[source] = 0;
    st.insert(make_pair(0,source));

    while( !st.empty() ){
        //fetch front node
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        //remove top node
        st.erase(st.begin());

        //traverse on neighbours
        for(auto neighbour: adjList[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){
                //Below Two Lines Not Necessary
                
                auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));
                //if record found then erase it

                if(record != st.end()){
                    st.erase(record);
                }

                //distance update 
                dist[neighbour.first] = nodeDistance + neighbour.second;

                //record push in set
                st.insert(make_pair(dist[neighbour.first],neighbour.first));

            }
        }
    }
    return dist;
}


int main(){
    vector<vector<int>> edges = {{0,1,5},{0,2,8},{1,2,9},{1,3,2},{2,3,6}};
    vector<int> result = dijsktra(edges,4,5,0);
    for(auto i:result){
        cout<<i<<" ";
    }
    return 0;
}