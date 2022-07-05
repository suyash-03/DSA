// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int left=0,right=m-1,bottom=n-1,top=0;
        int direction=1;
        vector<int> v;
        while(left<=right && top<=bottom)
        {
            if(direction==1)
            {
                for(int i=left;i<=right;i++) v.push_back(matrix[top][i]);
                direction=2;
                top++;
            }
            
            else if(direction==2)
            {
                for(int i=top;i<=bottom;i++) v.push_back(matrix[i][right]);
                direction=3;
                right--;
            }
            
            else if(direction==3)
            {
                for(int i=right;i>=left;i--) v.push_back(matrix[bottom][i]);
                direction=4;
                bottom--;
            }
            
            else if(direction==4)
            {
                for(int i=bottom;i>=top;i--) v.push_back(matrix[i][left]);
                direction=1;
                left++;
            }
        }
        return v;
        
    }
};

int main() {
    // Write C++ code here
    Solution s1;
    vector<vector<int>> toPass;
    vector<int> temp = {1,2,3};
    vector<int> temp2 = {4,5,6};
    vector<int> temp3 = {7,8,9};

    toPass.push_back(temp);
    toPass.push_back(temp2);
    toPass.push_back(temp3);
    vector<int> result = s1.spiralOrder(toPass);
    for(auto i: result){
        cout<<i<<" ";
    }
    return 0;
}