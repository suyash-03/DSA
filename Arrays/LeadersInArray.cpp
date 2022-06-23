#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> leaders(vector<int> A){
    vector<int> result;
     for (int i = 0; i < A.size(); i++)
    {
        int j;
        for (j = i+1; j < A.size(); j++)
        {
            if (A[i] < A[j])
                {
                 break;   
                }
        }   
        if (j == A.size()){
           result.push_back(A[i]); 
        } // the loop didn't break
            
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