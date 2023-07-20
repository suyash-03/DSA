#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Striver Solution -  Best

class Solution2 {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(m,vector<int>(n,0));

        for(int i=0; i < m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }else{
                    visited[i][j] = 0;
                }
            }
        }

        int tm = 0;
        vector<int> dRow = {-1,0,+1,0};
        vector<int> dCol = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm,t);
            q.pop();
            for(int i=0; i < 4; i++){
                int newR = r + dRow[i];
                int newC = c + dCol[i];
                if(newR < m && newR >= 0 && newC < n && newC >= 0 
                && visited[newR][newC] == 0 && grid[newR][newC] == 1 ){
                    q.push({{newR,newC},t+1});
                    visited[newR][newC] = 2;
                }
            }
        }

        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n ; j++){
                if(grid[i][j] == 1 && visited[i][j] != 2){
                    return -1;
                }
            }
        }

        return tm;
    }
};



class Solution {
public:
    struct Node{
        int timeFrame;
        pair<int,int> position;
    };
    
    int orangesRotting(vector<vector<int>> &grid) {
        queue<Node> q;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 2){
                    Node node;
                    node.timeFrame = 0;
                    node.position = {j,i};
                                    //x,y
                    q.push(node);
                }
            }
        }

        int currentTimeFrame = 0;

        while(!q.empty()){
            Node frontNode = q.front();
            q.pop();
            int x = frontNode.position.first;
            int y = frontNode.position.second;
            currentTimeFrame = frontNode.timeFrame;
            Node node;

            if(x+1 < n && grid[y][x+1] == 1){
                node.timeFrame = currentTimeFrame+1;
                node.position = {x+1,y};
                grid[y][x+1] = 2;
                q.push(node);
            }
            
            if(x-1 >= 0 && grid[y][x-1] == 1){
                node.timeFrame = currentTimeFrame+1;
                node.position = {x-1,y};
                grid[y][x-1] = 2;
                q.push(node);
            }
            
            if(y+1 < m && grid[y+1][x] == 1){
                node.timeFrame = currentTimeFrame+1;
                node.position = {x,y+1};
                grid[y+1][x] = 2;
                q.push(node);
            }

            if(y-1 >= 0 && grid[y-1][x] == 1){
                node.timeFrame = currentTimeFrame+1;
                node.position = {x,y-1};
                grid[y-1][x] = 2;
                q.push(node);
            }    
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return currentTimeFrame;
    }
};


int main(){
    vector<vector<int>> grid = {{2},{1}};
    Solution s;
    int res = s.orangesRotting(grid);
    cout<<res;
    return 0;
}
