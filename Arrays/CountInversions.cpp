#include <bits/stdc++.h>
#include <iostream>
using namespace std;    

// This question is about counting inversions in an array using Merge Sort.
// An inversion is a pair of indices (i, j) such that i < j and nums[i] > nums[j].
// The merge sort algorithm is modified to count these inversions while sorting the array. 

long long int merge(vector<int> &nums,int low,int middle, int high){
    int left = low;
    int right = middle+1;
    vector<int> temp;
    long long int inversionCount = 0;
    while(left <= middle && right <= high){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left]);
            left++;
        }else {
            temp.push_back(nums[right]);
            inversionCount += middle - left + 1;
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
    for(int i = low; i<=high; i++){
        nums[i] = temp[i - low];
    }
    return inversionCount;
}
long long int mergeSortAndCount(vector<int> &nums, int low, int high){
    if(low >= high){
        return 0;
    }
    int middle = (low+high)/2;
    long long int left = mergeSortAndCount(nums, low, middle);
    long long int right = mergeSortAndCount(nums, middle+1, high);
    long long int mergeCount = merge(nums,low,middle,high);
    return left + right + mergeCount;
}

int main(){
    vector<int> arr = {2, 4, 1, 3, 5};
    cout << "Number of inversions: " << mergeSortAndCount(arr, 0, arr.size() - 1) << endl;
    return 0;
}