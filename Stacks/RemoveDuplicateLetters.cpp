#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq;
        unordered_map<char, bool> used;
        stack<char> st;

        // Track remaining occurrences so we know whether a character can be
        // safely removed and added back later.
        for (auto c : s) {
            freq[c]++;
        }

        for (auto c : s) {
            freq[c]--;

            // Each character should appear only once in the answer.
            if (used[c]) {
                continue;
            }

            // Keep the stack lexicographically small. A larger top character
            // can be removed only if it appears again later.
            while (!st.empty() && c < st.top() && freq[st.top()] > 0) {
                used[st.top()] = false;
                st.pop();
            }

            st.push(c);
            used[c] = true;
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
