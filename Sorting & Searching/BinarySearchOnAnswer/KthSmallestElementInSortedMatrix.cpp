#include <vector>
using namespace std;

// General template for Binary Search on Answer questions:
//
// 1. Identify the answer range.
//    start = minimum possible answer
//    end   = maximum possible answer
//
// 2. Write a monotonic helper/check function.
//    bool isPossible(mid)
//    or
//    int countSomething(mid)
//
//    The important property:
//    - If mid works, then all values after/before it should also work,
//      depending on whether you are minimizing or maximizing the answer.
//
// 3. Binary search over the answer range.
//
//    int ans = -1;
//    while (start <= end) {
//        int mid = start + (end - start) / 2;
//
//        if (isPossible(mid)) {
//            ans = mid;
//            end = mid - 1;       // use this when finding minimum valid answer
//            // start = mid + 1;  // use this when finding maximum valid answer
//        } else {
//            start = mid + 1;     // move toward valid answer
//            // end = mid - 1;    // opposite direction for some problems
//        }
//    }
//
// 4. Return ans.
//
// In this problem:
// - Answer range is from matrix[0][0] to matrix[n - 1][n - 1].
// - For a chosen mid, count how many elements are <= mid.
// - If count >= k, mid can be the kth smallest or larger than it,
//   so store ans and search left for a smaller valid answer.

class Solution {
public:
    int countLesserElements(vector<vector<int>> &matrix, int mid){
        int n = matrix.size();
        int row = 0;
        int column = n -1;

        int count = 0;
        while(row < n && column >= 0){
            if(matrix[row][column] <= mid){
                count += (column + 1);
                row++;
            }else{
                column --;
            }
        }

        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // Binary Search on Answer
        int n = matrix.size();

        int start = matrix[0][0];
        int end = matrix[n-1][n-1];
        int ans = -1;
        while(start <= end){
            int mid = start + (end - start) / 2;

            if(countLesserElements(matrix, mid) >= k){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;
    int result = sol.kthSmallest(matrix, k);
    return 0;
}
