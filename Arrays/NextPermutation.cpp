class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();

        //Finding the Longest Prefix after which we can change
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        //If Index is -1 it is the largest pemutation
        if(index == -1){
            reverse(nums.begin(),nums.end());
            return;
        }

        //In the right of index element find the next greatest element and swap it with index
        for(int i = n-1; i > index; i--){
            if(nums[i] > nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }

        //Sort the array to the right of index
        auto it = nums.begin();
        advance(it,index+1);
        sort(it,nums.end());
        
    }
};
