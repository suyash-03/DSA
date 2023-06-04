#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> vec;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    vec.push_back(make_pair(i,j));
                }
            }
        }

        for(int i=0; i<vec.size(); i++){
            int r = vec[i].first;
            int c = vec[i].second;
            
            for(int x = 0; x<m; x++){
                matrix[x][c] = 0;
            }

            for(int y =0; y<n; y++){
                matrix[r][y] = 0;
            }
        }
    }

    //O(1) Space
    void setZeroes2(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool flag1 = false, flag2 = false;
        for(int i=0; i<n; i++){
            if(matrix[i][0] == 0){
                flag1 = true;
            }
        }
        for(int j=0; j<m; j++){
            if(matrix[0][j] == 0){
                flag2 = true;
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(flag1 == true){
            for(int i=0; i<n; i++){
                matrix[i][0] = 0;
            }
        }
        if(flag2 == true){
            for(int j=0; j<m; j++){
                matrix[0][j] = 0;
            }
        }
    }

int main(){
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(matrix);

    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}