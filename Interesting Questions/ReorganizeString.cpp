#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

// In this problem, we need to reorganize the string such that no two adjacent characters are the same.
// If it's not possible, we return an empty string.
// We can use a max-heap (priority queue) to always pick the character with the highest remaining frequency
// and place it next in the result string, ensuring that we don't place the same character consecutively.
// If we have a previously used character that still has remaining frequency, we push it back into the heap
// after placing a different character.
// This approach ensures that we always have the best chance of avoiding adjacent duplicates.
// Time Complexity: O(n log k), where n is the length of the string and k is the number of unique characters.
// Space Complexity: O(k) for the frequency map and the priority queue.
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        priority_queue<pair<int,char>> pq;
        for (auto &it : freq) pq.push({it.second, it.first});

        string ans = "";

        pair<int,char> prev;
        bool hasPrev = false;

        while (!pq.empty() || hasPrev) {

            if (hasPrev && pq.empty()) 
                return "";   // remaining char cannot be placed

            auto current = pq.top();
            pq.pop();

            ans += current.second;
            current.first--;

            // push previous back
            if (hasPrev) {
                pq.push(prev);
                hasPrev = false;
            }

            // store current as prev if still remaining
            if (current.first > 0) {
                prev = current;
                hasPrev = true;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string s = "aaabbc";
    string result = sol.reorganizeString(s);
    return 0;
}