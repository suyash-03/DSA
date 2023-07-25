#include <vector>
#include <bits/stdc++.h>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int res = nums[0];
        for(int i=1; i < nums.size(); i++){
            res = res ^ nums[i]; 
        }

        return res;
    }
};