#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Concept behind deque for Sliding Window Maximum:
//
// We store indices in the deque, not values.
// The deque is maintained in decreasing order of values:
// nums[q.front()] is always the maximum element of the current window.
//
// Why remove from the back?
// If nums[r] is greater than nums[q.back()], then q.back() can never be the
// maximum for this window or any future window that also contains nums[r].
// So we remove smaller elements from the back before pushing r.
//
// Why remove from the front?
// q.front() may become outside the current window. If q.front() < l, that index
// is expired and must be removed.
//
// Dry run:
// nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
//
// r = 0, nums[r] = 1
// q = [0]                 values = [1]
//
// r = 1, nums[r] = 3
// 3 > 1, pop index 0
// q = [1]                 values = [3]
//
// r = 2, nums[r] = -1
// -1 is smaller than 3, push index 2
// q = [1, 2]              values = [3, -1]
// window [1, 3, -1], max = nums[q.front()] = 3
//
// Move l to 1.
// r = 3, nums[r] = -3
// q = [1, 2, 3]           values = [3, -1, -3]
// window [3, -1, -3], max = 3
//
// Move l to 2.
// r = 4, nums[r] = 5
// 5 > -3, pop index 3
// 5 > -1, pop index 2
// 5 > 3, pop index 1
// q = [4]                 values = [5]
// window [-1, -3, 5], max = 5
//
// The same rule continues, giving output:
// [3, 3, 5, 5, 6, 7]

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;

        deque<int> q; // indices
        vector<int> ans;
        while(r < nums.size()){
            // Maintain a monotonically decreasing deque.
            // The front always stores the index of the maximum value in window.
            while(!q.empty() && nums[r] > nums[q.back()]){
                q.pop_back();
            }

            q.push_back(r);

            if(l > q.front()){
                q.pop_front();
            }

            if((r + 1 - l) >= k){
                ans.push_back(nums[q.front()]);
                l++;
            }
            r++;
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<int> vec = {1,3,-1,-3,5,3,6,7}; int k = 2;
    vector<int> res = s.maxSlidingWindow(vec,k);

    for(auto i:res){
        cout<<i<<" ";
    }

    return 0;
}
