#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        do{
            result.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> result;
    void backtrack(int l,int r,vector<int> &nums){
        if(l==r){
            result.push_back(nums);
            return;
        }
        for(int i=l; i<=r; i++){
            swap(nums[l],nums[i]);
            backtrack(l+1,r,nums);
            swap(nums[l],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(0,nums.size()-1,nums);
        return result;
    }
};
