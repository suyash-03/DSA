#include <cmath>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    // Custom comparator skeleton for priority_queue:
    //
    // struct Compare {
    //     bool operator()(T a, T b) {
    //         return ...;
    //     }
    // };
    //
    // priority_queue<T, vector<T>, Compare> pq;
    //
    // Note:
    // - return true means a has lower priority than b.
    // - For max-heap behavior, return a < b.
    // - For min-heap behavior, return a > b.
    struct Compare {
        bool operator()(pair<vector<int>, int> p1, pair<vector<int>, int> p2) {
            return p1.second < p2.second;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<vector<int>, int>, vector<pair<vector<int>, int>>, Compare> pq;
        for(int i = 0; i < points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];

            int sqDist = pow(x,2) + pow(y,2);
            pair<vector<int>, int> p = {points[i], sqDist};
            pq.push(p);
            
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;
        
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{1, 3}, {-2, 2}, {5, 8}};
    int k = 2;
    vector<vector<int>> result = sol.kClosest(points, k);
    return 0;
}
