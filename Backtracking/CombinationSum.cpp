// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets;
    void dfs(int index,vector<int> candidates,vector<int> temp,int target){
        if(index >= candidates.size()){
            return;
        }
        if(accumulate(temp.begin(),temp.end(),0) == target){
            subsets.push_back(temp);
            return;
        }
        if(accumulate(temp.begin(),temp.end(),0) > target){
            return;
        }
        
        
        //Take the Element in Subset
        temp.push_back(candidates[index]);
        dfs(index,candidates,temp,target);
        
        //Don't take the element
        temp.pop_back();
        dfs(index+1,candidates,temp,target);
    };
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        dfs(0,candidates,temp,target);
        return subsets;
    }
};

int main() {
    Solution s;
    vector<int> v = {2,3,5};
    vector<vector<int>> result;
    result = s.combinationSum(v,8);
    
         //Printing Result
        for(auto i:result){
            for(auto j:i){
                cout<<j<<",";
            }
            cout<<endl;
        }
        
    return 0;
}