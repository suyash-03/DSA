#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//No of subarrays with sum K
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //Map for storing prefix sum
        unordered_map<int,int> myMap;
        myMap[0] = 1;
        int prefixSum = 0;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            prefixSum = prefixSum + nums[i];
            if(myMap.find(prefixSum - k) != myMap.end()){
                count = count + myMap[prefixSum-k];
            }
            myMap[prefixSum]++;
        }
        return count;
    }
};
