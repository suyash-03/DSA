#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int search(vector<int> &nums, int k) {
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;
        while (start <= end) {
            int middle = (start + end)/2;
            if(nums[middle] == k){
                ans = middle;
                break;
            }
            //left half is sorted
            else if(nums[start] <= nums[middle]){
                // k lies in left half
                if(nums[start] <= k && k <= nums[middle]){
                    end = middle - 1;
                }else{
                    start = middle + 1;
                }
            }
            // right half is sorted
            else{
                // k lies in right half
                if(nums[middle] <= k && k <= nums[end]){
                    start = middle + 1;
                }else{
                    end = middle - 1;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    int k = 0;
    int result = sol.search(nums, k);
    return 0;
}