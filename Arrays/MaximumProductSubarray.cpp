#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//Much more intuitive solution than modified Kadane's Algorithm
//using Prefix and Suffix Product
class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int prefixProduct = 1;
        int suffixProduct = 1;
        int ans =INT_MIN;
        int n = nums.size();
        for(int i=0; i < n; i++){
            if(prefixProduct == 0) prefixProduct = 1;
            if(suffixProduct == 0) suffixProduct = 1;

            prefixProduct = prefixProduct * nums[i];
            suffixProduct = suffixProduct * nums[n-i-1];

            ans = max(ans,max(suffixProduct,prefixProduct));
        }


        return ans;
    }
};


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
