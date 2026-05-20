#include <algorithm>
#include <vector>
using namespace std;

// 1. Non-Overlapping Intervals
// Goal: Keep as many intervals as possible, which means remove the minimum
// number of overlapping intervals.
// Strategy: Sort by end time.
// Why: Pick the interval that finishes as early as possible. The sooner an
// interval finishes, the more room it leaves for future intervals to fit.
// This is a greedy choice focused on maximizing how many intervals can remain.
//
// 2. Merge Intervals
// Goal: Combine overlapping intervals into one continuous block.
// Strategy: Sort by start time.
// Why: To merge effectively, you need to know whether the next interval starts
// before the current interval ends. Sorting by start time processes intervals
// chronologically from left to right. If intervals[i][0] <= current_end, they
// overlap, so extend current_end to max(current_end, intervals[i][1]).
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), cmp);

        int res = 0;
        vector<int> lastInterval = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            if (lastInterval[1] > intervals[i][0]) {
                res++;
            } else {
                lastInterval = intervals[i];
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int result = sol.eraseOverlapIntervals(intervals);
    return 0;
}
