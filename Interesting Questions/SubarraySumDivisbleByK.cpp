#include <vector>   
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainderFreqMap;
        remainderFreqMap[0] = 1;

        int prefixSum = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
            int remainder = prefixSum % k;
            remainder = (remainder + k) % k;
            if(remainderFreqMap.find(remainder) != remainderFreqMap.end()){
                res += remainderFreqMap[remainder];
            }
            remainderFreqMap[remainder]++;
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;
    int result = sol.subarraysDivByK(nums,k);
    return 0;
}