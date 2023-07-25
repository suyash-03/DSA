#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<vector<int>> ansMatrix(m,vector<int>(m,0));
        cout<<"Here";
        for(int i=m; i>0; i--){
            
            //AnswerMatrix Column Loop
            for(int j = 0; j < m; j++){

            
                for(int k = 0; k < m; k++){
                    matrix[i][k]=ansMatrix[k][j];
                }


            }
        }
        
        

        for(int i = 0; i<m; i++){
            for(int j =0; j<m; j++){
                matrix[i][j] = ansMatrix[i][j];
            }
        }


        for(int i = 0; i<m; i++){
            for(int j=0; j<m ;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    int main(){
        vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
        rotate(matrix);
        return 0;
    }