#include <vector>
#include <bits/stdc++.h>

/*
A^A = 0
A^A^A = A
A^A^B = B

Even A's will give 0

For XOR -  Same Input give 0 ( 0 0 -> 0, 1 1 -> 0)
        - Different Input give 2 (0 1 -> 1, 1 0 -> 0)
*/

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
