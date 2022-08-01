#include<bits/stdc++.h>
using namespace std;

long long solve (int N, int M, vector<vector<int> > A) {
   // Write your code here
   int nodes = N;
   int edges = M;

   //create adjacency list
   unordered_map<int,list<pair<int,int>>> adjList;

   for(int i=0; i<edges; i++){
       int u = A[i][0];
       int v = A[i][1];
       int w = A[i][2];

       adjList[u].push_back(make_pair(v,w));
   }

   vector<int> dist(nodes+1,INT_MAX);
   set<pair<int,int>> st;
   dist[1] = 0;
   st.insert(make_pair(0,1));
                   //d,n
   while( !st.empty() ){
       auto front = *(st.begin());
       int frontNode = front.second;
       int nodeDistance = front.first;

       st.erase(st.begin());

       for(auto neighbour: adjList[frontNode]){
           if(nodeDistance + neighbour.second < dist[neighbour.first]){
               //updating the value
               dist[neighbour.first] = nodeDistance + neighbour.second;
               //pushing in set
               st.insert(make_pair(dist[neighbour.first],neighbour.first));
           }
       }
   }
   if(dist[N] != INT_MAX){
    int toRet = dist[nodes];
    return toRet;
   }
   else {
       return -1;
   }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int M;
        cin >> M;
        vector<vector<int> > A(M, vector<int>(3));
        for (int i_A = 0; i_A < M; i_A++)
        {
        	for(int j_A = 0; j_A < 3; j_A++)
        	{
        		cin >> A[i_A][j_A];
        	}
        }

        long long out_;
        out_ = solve(N, M, A);
        cout << out_;
        cout << "\n";
    }
}