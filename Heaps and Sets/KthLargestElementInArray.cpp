#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        // Keep only the k largest elements seen so far.
        // The smallest among those k elements stays at the top.
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};
