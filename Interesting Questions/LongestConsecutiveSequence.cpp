#include <iostream>
#include <bits/stdc++.h>
#include <set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        set<int> st(nums.begin(), nums.end());

        vector<int> uNums;
        for(auto num: st){
            uNums.push_back(num);
        }

        sort(uNums.begin(), uNums.end());
        int i = 0;
        int j = 1;

        int n = uNums.size();
        int len = 1;
        while(j < n){
            if(uNums[j] - uNums[j-1] == 1){
                len = max(len, j-i+1);
                j++;
            }else{
                i++;
                j=i+1;
            }
        }

        return len;
    }
};
