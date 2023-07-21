/*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands
where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered
to be distinct if and only if one island is not equal to another (not rotated or reflected).
*/

class Solution {
  public:
  
    void dfsUtil(int i,int j,int srcX,int srcY,int m,int n,vector<vector<int>> &grid,vector<pair<int,int>> &temp){
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1){
            return;
        }
        
        grid[i][j] = 2;
        int delX = i - srcX;
        int delY = j - srcY;
        temp.push_back({delX,delY});
        
        dfsUtil(i+1,j,srcX,srcY,m,n,grid,temp);
        dfsUtil(i,j+1,srcX,srcY,m,n,grid,temp);
        dfsUtil(i-1,j,srcX,srcY,m,n,grid,temp);
        dfsUtil(i,j-1,srcX,srcY,m,n,grid,temp);
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        set<vector<pair<int,int>>> st;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    vector<pair<int,int>> temp = {};
                    dfsUtil(i,j,i,j,m,n,grid,temp);
                    st.insert(temp);
                }
            }
        }
      
        return st.size();
    }
};
