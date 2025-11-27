#include <vector>
#include <algorithm>    
using namespace std;

// In this problem, we need to insert a new interval into a list of non-overlapping intervals
// sorted by their start times, and merge any overlapping intervals.
// The approach is to first add the new interval to the list, sort the list based on
// the start times, and then iterate through the sorted list to merge overlapping intervals.
// Time Complexity: O(n log n) due to sorting the intervals.
// Space Complexity: O(n) for storing the merged intervals. 
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> combIntervals;
        for(auto it: intervals){
            combIntervals.push_back(it);
        }
        combIntervals.push_back(newInterval);

        sort(combIntervals.begin(), combIntervals.end(), cmp);
        vector<int> lastInterval = combIntervals[0];

        vector<vector<int>> ans;
        for(int i = 0; i < combIntervals.size(); i++){
            if(lastInterval[1] >= combIntervals[i][0]){
                lastInterval[1] = max(lastInterval[1], combIntervals[i][1]);
            }else{
                ans.push_back(lastInterval);
                lastInterval = combIntervals[i];
            }
        }
        ans.push_back(lastInterval);
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};
    vector<vector<int>> result = sol.insert(intervals, newInterval);
    return 0;
}