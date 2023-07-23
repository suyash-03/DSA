class Solution {
public:
    unordered_map<int,list<int>> createAdjacencyList(vector<vector<int>> &graph){
        unordered_map<int,list<int>> adjList;
        for(int i=0; i < graph.size(); i++){
            for(int j = 0; j < graph[i].size(); j++){
                int u = i;
                int v = graph[i][j];
                adjList[u].push_back(v);
            }
        }
        return adjList;
    }

    // basically check whether we can color all the nodes of a graph without coloring adjacent nodes samez
   bool isBipartiteUtil(int node, unordered_map<int, list<int>>& adjList, vector<int>& colors) {
    queue<int> q;
    q.push(node);
    colors[node] = 0;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto adjacentNode : adjList[front]) {
            //If the adjacent Node is not colored, color it with the compliment of the front node
            if (colors[adjacentNode] == -1) {
                colors[adjacentNode] = !colors[front];
                q.push(adjacentNode);
            } else if (colors[adjacentNode] == colors[front]) {
                //if it's colored with the same color as the front node, return false
                return false;
            }
        }
    }

    return true;
}

    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,list<int>> adjList = createAdjacencyList(graph);
        int nodes = graph.size();
        vector<int> colors(nodes,-1);

        //for loop for connected components
        for(int node = 0; node < nodes; node++){
            if(colors[node] == -1){
                bool res = isBipartiteUtil(node,adjList,colors);
                if(res == false){
                    return false;
                }
            }
        }

        return true;
    }
};
