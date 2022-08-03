#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void dfs(int index,vector<int> nums,vector<int> temp){
        if(index >= nums.size()){
            result.push_back(temp);
            return;
        }

        //Decison to include
        temp.push_back(nums[index]);
        dfs(index+1,nums,temp);

        //Decison not to include
        temp.pop_back();
        dfs(index+1,nums,temp);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0) return result;
        vector<int> temp;
        dfs(0,nums,temp);
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    s.subsets(nums);
    return 0;
}
