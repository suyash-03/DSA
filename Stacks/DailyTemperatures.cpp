#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);

        // Monotonic decreasing stack of indices.
        // The temperatures at these indices are waiting for a warmer day, and
        // from bottom to top they stay in decreasing order.
        stack<int> st;

        for (int i = 0; i < n; i++) {
            int today = temperatures[i];

            // If today is warmer than the day at stack top, today is the next
            // warmer day for that index. Keep resolving while this is true.
            while (!st.empty() && today > temperatures[st.top()]) {
                int index = st.top();
                st.pop();
                ans[index] = i - index;
            }

            // Current day now waits for a future warmer temperature.
            st.push(i);
        }

        return ans;
    }
};
