#include <algorithm>
#include <vector>
using namespace std;

/*
Problem: Rotate Array

Given an integer array nums, rotate the array to the right by k steps.

Example:
Input:  nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

Approach used below:
1. Normalize k using k % n.
2. Reverse the whole array.
3. Reverse the first k elements.
4. Reverse the remaining n - k elements.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return;

        k = k % n;
        if(k == 0) return;

        reverse(nums.begin(), nums.end());

        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

/*
Extra-space approach:

This also works, but it uses O(n) extra space because it stores the two
parts of the rotated array in separate vectors.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        if(k == 0) return;

        vector<int> fp;
        for(int i = n-k; i < n; i++){
            fp.push_back(nums[i]);
        }

        vector<int> sp;
        for(int i = 0; i < n-k; i++){
            sp.push_back(nums[i]);
        }

        for(int i = 0; i < k; i++){
            nums[i] = fp[i];
        }

        for(int j = k; j < n; j++){
            nums[j] = sp[j-k];
        }
    }
};

The current active solution is optimized because it rotates the array in-place
using reverse(), so it avoids the extra vectors.
*/
