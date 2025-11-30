#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n = nums.size();
        unordered_map<int,int> myMap;

        int ans = 0;
        int prefixSum = 0;
        for(int i = 0; i < n; i++){
            prefixSum += nums[i];

            if(prefixSum == k){
                ans = max(ans,i+1);
            }
            
            if(myMap.find(prefixSum-k) != myMap.end()){
                ans = max(ans, i - myMap[prefixSum - k]);
            }
            //Only Store the first occurence of each prefix sum
            if(myMap.find(prefixSum) == myMap.end()){
                myMap[prefixSum] = i;
            }            
        } 

        return ans;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1,-1,5,-2,3};
    int k = 3;
    int result = sol.longestSubarray(nums,k);
    return 0;
}