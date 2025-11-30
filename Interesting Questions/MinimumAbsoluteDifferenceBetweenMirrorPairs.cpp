#include <vector>
#include <unordered_map>    
#include <climits>
using namespace std;

class Solution {
public:
    int reverseElement(int num){
        int rev = 0;
        while(num > 0){
            rev = rev * 10 + (num % 10);
            num /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> rightIndex;
        int ans = INT_MAX;
        int n = nums.size();

        for (int i = n - 1; i >= 0; --i) {
            int r = reverseElement(nums[i]);
            if (rightIndex.count(r)) {
                ans = min(ans, rightIndex[r] - i);
            }
            // store/overwrite so map[v] is the nearest index to the right for future (earlier) i
            rightIndex[nums[i]] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {12, 21, 13, 31};
    int result = sol.minMirrorPairDistance(nums);
    return 0;
}