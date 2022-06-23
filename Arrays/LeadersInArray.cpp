#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> leaders(vector<int> A){
     vector<int> result;
    //Traverse the array from right to left;
    int length = A.size();
    int maxFromRight = A[length-1];
    result.push_back(A[length - 1]);
    
    for(int i = length-2; i>=0 ; i--){
        if(A[i] > maxFromRight){
            result.push_back(A[i]);
            maxFromRight = A[i];
        }
    }
    return result;
}

int main(){
    vector<int> A;
    A.push_back(16); A.push_back(17);
    A.push_back(4); A.push_back(3);
    A.push_back(5); A.push_back(2);
    vector<int> result = leaders(A);
    for(int i=0 ;i< result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}