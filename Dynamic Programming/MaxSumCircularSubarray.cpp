#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int noWrapKadane(vector<int> &nums){
        int maxCurrent = nums[0];
        int maxGlobal = nums[0];
        for(int i=1; i<nums.size(); i++){
            maxCurrent = max(nums[i],maxCurrent + nums[i]);
            if(maxCurrent > maxGlobal){
                maxGlobal = maxCurrent;
            }
        }
        return maxGlobal;
    }
    
    int wrapKadane(vector<int> &nums){
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        vector<int> nums2(nums.size(),0);
        for(int i=0; i<nums.size(); i++){
            nums2[i] = nums2[i] - nums[i];
        }
        
        int maxNoWrap = noWrapKadane(nums2);
        
        return (sum + maxNoWrap);
        
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        /*
        Firstly find Maximum subarray using kadane's algorithm considering 
        it is not present at the ends
        */
        int a = noWrapKadane(nums);
        
         /*
         Now find the maximum subarray of negative of array using Kadane's algorithm
         return sum of the array  + sum of max negative continous subarray
         max of these two values will be the answer
        */
        int b = wrapKadane(nums);
        
        if(b == 0){
            return a;
        }else{
            return max(a,b);
        }
        
    }
};
