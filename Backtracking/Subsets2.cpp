#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<vector<int>> st;
    void dfs(int index,vector<int> &nums,vector<int> temp){
        if(index >= nums.size()){
            sort(temp.begin(),temp.end());
            st.insert(temp);
            return;
        }
        
        //Take The Element
        temp.push_back(nums[index]);
        dfs(index+1,nums,temp);
        
        //Don't take the element
        temp.pop_back();
        dfs(index+1,nums,temp);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp = {};
        vector<vector<int>> result = {};
        dfs(0,nums,temp);
        for(auto it:st){
            result.push_back(it);
        }
        return result;
    }
};