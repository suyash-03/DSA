#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int numDiagonalElements = numRows-2;
        int numVerticalColumns = (s.size()/numRows);
        vector<vector<char>> matrix(numRows,vector<char>(s.size(),'0'));
        int count = 0;
        int strCount = 0;
        int currentColumn = 0;
        int currentRow = 0;
        while(strCount != s.size()){
            matrix[currentRow][currentColumn] = s[strCount];
            count++;
            strCount++;
            currentRow++;

            if(strCount == s.size()){
                break;
            }

            if(count == numRows){
                currentRow--;
                for(int j=0; j<numDiagonalElements; j++){
                    currentColumn = currentColumn+1;
                    matrix[currentRow-1-j][currentColumn] = s[strCount];
                    strCount++;
                    if(strCount == s.size()){
                        break;
                    }
                }
                count = 0;
                currentRow = 0;
                currentColumn = currentColumn + 1;
            }
        }

        string result;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                cout<<matrix[i][j]<<" ";
                if(matrix[i][j] >= 65 && matrix[i][j] <= 90){
                    result = result + matrix[i][j];
                }
            }
            cout<<endl;
        }
        return result;
        
    }
};

int main(){
    Solution s1;
    string result = s1.convert("PAYPALISHIRING",4);
    cout<<endl;
    cout<<result;
    return 0;
}