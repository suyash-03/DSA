#include <bits/stdc++.h>
using namespace std;

/*
Example:
nums = [1, 2, 3, 4]

First pass stores product of all elements to the left:
ans = [1, 1, 2, 6]

Second pass multiplies product of all elements to the right:
right products used = [24, 12, 4, 1]
final ans = [24, 12, 8, 6]
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // ans[i] first stores the product of all elements before index i.
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix = nums[i] * prefix;
        }

        // Multiply by the product of all elements after index i.
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = ans[i] * suffix;
            suffix = suffix * nums[i];
        }

        return ans;
    }
};
