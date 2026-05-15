#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<algorithm>
using namespace std;

/*
    Alien Dictionary

    Problem idea:
    We are given words sorted according to an unknown alien alphabet.
    From this sorted order, we need to find one valid ordering of the K alien
    characters.

    Reasoning:
    Compare every pair of adjacent words.

    Example:
    word1 = "baa"
    word2 = "abcd"

    The first different character is:
    'b' and 'a'

    Since word1 appears before word2 in the dictionary, 'b' must come before 'a'
    in the alien alphabet. So we create a directed edge:

    b -> a

    After comparing all adjacent pairs, the problem becomes:
    Find a topological ordering of this directed graph.

    Important cases:
    1. If there is a cycle, no valid character ordering exists.
    2. If word1 is longer than word2 and word2 is a prefix of word1,
       the dictionary order is invalid.

    Time Complexity: O(total characters in dictionary + K)
    Space Complexity: O(K + edges)
*/

class Solution {
public:
    bool dfs(unordered_map<int,list<int>> &adjList, unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsVisited, int node, string &result){
        visited[node] = 1;
        dfsVisited[node] = 1;

        for(auto i: adjList[node]){
            if(!visited[i]){
                if(dfs(adjList,visited,dfsVisited,i,result)) return true;
            }else if(dfsVisited[i]){
                // Back edge found, so the directed graph has a cycle.
                return true;
            }
        }

        dfsVisited[node] = 0;

        // DFS topological sort: add the node after all its neighbours are done.
        result+=(char)(node+'a');
        return false;
    }
	string findOrder(string dict[], int N, int K) {
		unordered_map<int,list<int>> adjList;

        // Build graph by comparing adjacent words in the sorted dictionary.
        for(int i = 0; i < N-1; i++){
            string word1 = dict[i];
            string word2 = dict[i+1];
            int len = min(word1.size(), word2.size());

            // Invalid case: "abcd" cannot appear before "abc".
            if((word1.size() > word2.size()) && (word1.substr(0,len) == word2)) return "";

            for(int j = 0; j < len; j++){
                if(word1[j] != word2[j]){
                    // word1[j] must come before word2[j].
                    adjList[word1[j]-'a'].push_back(word2[j] - 'a');
                    break;
                }
            }
        }

        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsVisited;
        bool hasCycle = false;
        string result = "";
        
        // Run DFS for all K characters because the graph can be disconnected.
        for(int node = 0; node < K; node++){
            if(!visited[node]){
                hasCycle = dfs(adjList, visited, dfsVisited, node, result);
                if(hasCycle) return "";
            }
        }

        // Nodes were added in reverse topological order.
        reverse(result.begin(), result.end());
        return result;
	}
};
