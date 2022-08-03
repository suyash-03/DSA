#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        vector<vector<int>> result;
        do{
            st.insert(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        
        for(auto it:st){
            result.push_back(it);
        }
        
        return result;
    }
};