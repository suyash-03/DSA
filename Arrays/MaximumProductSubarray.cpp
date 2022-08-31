#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ma = nums[0];
        int mi = nums[0];
        int res = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i] < 0){
                swap(ma,mi);
            }
            
            ma = max(nums[i],nums[i]*ma);
            mi = min(nums[i],nums[i]*mi);

            res = max(ma,res);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> temp = {2,3,-2,4};
    int res = s.maxProduct(temp);
    cout<<res;
    return 0;
}