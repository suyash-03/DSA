#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int m = A.size();
    vector<vector<int>> res;
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A[i].size(); j++){
            if(A[i][j] != -1){
                vector<int> temp;
                int i2 = i;
                int j2 = j;
                while(i2 < m && j2 >= 0){
                    temp.push_back(A[i2][j2]);
                    A[i2][j2] = -1;
                    i2 = i2+1;
                    j2 = j2-1;
                }
                res.push_back(temp);    
            }

        }
    }
    
    return res;
}
