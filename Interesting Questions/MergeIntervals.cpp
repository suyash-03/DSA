#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), cmp);

        // Keep one active interval and extend it while overlaps continue.
        vector<int> lastInterval = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            if (lastInterval[1] >= intervals[i][0]) {
                lastInterval[1] = max(lastInterval[1], intervals[i][1]);
            } else {
                ans.push_back(lastInterval);
                lastInterval = intervals[i];
            }
        }

        ans.push_back(lastInterval);
        return ans;
    }
};
