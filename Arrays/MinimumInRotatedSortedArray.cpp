#include <bits/stdc++.h>
#include <iostream>
using namespace std;    

int minimumInRotatedSortedArray(vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;

    while (start < end) {
        int middle = (start + end) / 2;

        // If the middle element is greater than the end element,
        // it means the minimum is in the right half.
        if (arr[middle] > arr[end]) {
            start = middle + 1;
        } else { // Otherwise, it is in the left half or at middle.
            end = middle;
        }
    }

    return arr[start]; // or arr[end], both are the same here.
}

int findMin(vector<int> &arr) {
    int start = 0;
    int end = arr.size() - 1;
    int ans = arr[0];
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[start] <= arr[mid]) {  // left array is sorted
            ans = min(ans, arr[start]);
            start = mid + 1;
        }else {
            ans = min(ans, arr[mid]);
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int minElement = findMin(arr);
    cout << "Minimum element is: " << minElement << endl;
    return 0;
}