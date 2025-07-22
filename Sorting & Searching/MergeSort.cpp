#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void merge(vector<int> &nums, int low, int middle, int high){
    int left = low;
    int right = middle + 1;
    vector<int> temp;
    while(left <= middle && right <= high){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left]);
            left++;
        } else {
            temp.push_back(nums[right]);
            right++;
        }
    }
    while(left <= middle){
        temp.push_back(nums[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(nums[right]);
        right++;
    }
    for(int i = low; i <= high; i++){
        nums[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &nums, int low, int high) {
    if (low >= high) {
        return;
    }
    int middle = (low + high) / 2;
    mergeSort(nums, low, middle);
    mergeSort(nums, middle + 1, high);
    merge(nums, low, middle, high);
}

int main() {
    vector<int> nums = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(nums, 0, nums.size() - 1);
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}