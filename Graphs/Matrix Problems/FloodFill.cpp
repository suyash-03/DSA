#include <iostream>
#include <vector>
using namespace std;    
class Solution {
public:
    void dfs(vector<vector<int>> &image, int i, int j, int m, int n, int startColor, int newColor){
        if(i >= n || i < 0 || j >= m || j < 0 || image[i][j] != startColor){
            return;
        }
        if(image[i][j] != newColor){
            image[i][j] = newColor;
            dfs(image,i+1,j,m,n,startColor, newColor);
            dfs(image,i-1,j,m,n,startColor, newColor);
            dfs(image,i,j+1,m,n,startColor, newColor);
            dfs(image,i,j-1,m,n,startColor, newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == sr && j == sc){
                    int startColor = image[i][j];
                    dfs(image,i,j,m,n,startColor, color);
                }
            }
        }

        return image;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);
    
    for(const auto& row : result) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}