#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>> generate(int numRows) {
        vector<vector<int>> A;
        if(numRows == 1){
            vector<int> r1 = {1};
            A.push_back(r1);
            return A;
        }else if(numRows == 2){
            vector<int> r1 = {1};
            vector<int> r2 = {1,1};
            A.push_back(r1);
            A.push_back(r2);
            return A;
        }else{
            vector<int> r1 = {1};
            vector<int> r2 = {1,1};
            A.push_back(r1);
            A.push_back(r2);
            for(int i=2 ; i<numRows; i++){
                vector<int> temp(i+1);
                A.push_back(temp);
                for(int j=1; j< i; j++){
                    A[i][0] = 1;
                    A[i][i] = 1;
                    A[i][j] = A[i-1][j-1] + A[i-1][j];
                }
            }
            return A;
        }
        
    }

    int main(){
        vector<vector<int>> vect;
        vect = generate(5);
        for (int i = 0; i < vect.size(); i++)
        {
            for (int j = 0; j < vect[i].size(); j++)
            {
                cout << vect[i][j] << " ";
                }    
                cout << endl;
                }
        return 0;
    }