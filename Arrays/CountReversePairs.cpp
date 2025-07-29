#include <bits/stdc++.h>
#include <iostream>
using namespace std;    

int reversePairCount = 0;
void countReversePairs(vector<int> &nums, int low, int middle, int high){
    int right = middle + 1;
    // This function counts the reverse pairs in the array
    // A reverse pair is defined as a pair (i, j) such that i < j and nums[i] > 2 * nums[j].
    // It iterates through the left half of the array and for each element, it finds how many elements in the right half are less than half of that element.
    for(int left = low; left <= middle; left++){
        while(right <= high && nums[left] > 2 * nums[right]){
            right++;
        }
        reversePairCount += (right - (middle + 1));
        // The count is incremented by the number of elements in the right half that satisfy the condition.
    }
}

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
// Merge Sort function to sort the array
// It recursively divides the array into halves and merges them back in sorted order.
// The merge function is used to combine two sorted halves into a single sorted array.
// The time complexity of merge sort is O(n log n) and it is a stable sorting algorithm.
// It is often used in scenarios where stable sorting is required or when dealing with large datasets.
            

void mergeSort(vector<int> &nums, int low, int high){
    if (low < high) {
        int middle = low + (high - low) / 2;
        mergeSort(nums, low, middle);
        mergeSort(nums, middle + 1, high);
        countReversePairs(nums, low, middle, high);
        merge(nums, low, middle, high);

    }
}

int main(){
    vector<int> nums = {5, 2, 6, 1};
    mergeSort(nums, 0, nums.size() - 1);
    cout << "Sorted Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Reverse pairs count: " << reversePairCount << endl;    
    return 0;
}