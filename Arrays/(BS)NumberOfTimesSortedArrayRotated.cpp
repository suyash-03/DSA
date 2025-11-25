#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int start = 0;
        int end = nums.size() - 1;

        // Basically we need to find the index of the smallest element
        while(start <= end){
            //Array is sorted
            if(nums[start] <= nums[end]){
                return start;
            }
            int middle = (start + end)/2;
            if(nums[start] <= nums[middle]){
                start = middle + 1;
            }else{
                end = middle;
            }
        }

        return start;
    }
};

int main()
{
    vector<int> arr = {15, 18, 2, 3, 6, 12};
    Solution sol;
    cout << sol.findKRotation(arr);
    return 0;
}