/*

bool isGraphBpUtil(int node,int color,unordered_map<int,list<int>> &adjList,vector<int> &colors){
	colors[node] = color;
	for(auto adjacentNode: adjList[node]){
		if(colors[adjacentNode] == -1){
			colors[adjacentNode] = !color;
			bool res = isGraphBpUtil(adjacentNode, !color, adjList, colors);
			if(res == false) return false;
		}else if(colors[adjacentNode] == color){
			return false;
		}
	}
	return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	unordered_map<int,list<int>> adjList = createAdjacencyList(edges);
	int nodes = edges.size();
	vector<int> colors(nodes,-1);
	for(int node =0; node<nodes; node++){
		if(colors[node] == -1){
			bool res =isGraphBpUtil(node,0,adjList,colors);
			if(res == false){
				return false;
			}
		}
	}

	return true;
}

*/
