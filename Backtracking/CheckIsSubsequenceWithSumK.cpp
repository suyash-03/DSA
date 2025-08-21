#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
  public:
    bool ans = false;
    void dfs(vector<int> &nums, int k, int index){
        if(ans) return;
        
        if(k == 0){
            ans = true;
            return;
        }
        if(index >= nums.size() || k < 0){
            return;
        }
        

        dfs(nums, k - nums[index], index+1);
        dfs(nums, k, index+1);
    }
    bool checkSubsequenceSum(int n, vector<int>& nums, int k) {
        // Code here
        dfs(nums,k,0);
        return ans; 
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 5;
    cout << sol.checkSubsequenceSum(nums.size(), nums, k) << endl;
    return 0;
}