#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0;
        int column = m - 1;
        //O(n+m)
        while(row < n && column >= 0){
            if(matrix[row][column] == target){
                return true;
            }else if(matrix[row][column] < target){
                row++;
            }else{
                column--;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 5;
    bool result = sol.searchMatrix(matrix, target);
    return 0;
}
