#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Core idea:
    // We need the smallest substring of s that contains every character of t,
    // including duplicates. For example, if t = "AABC", the window must contain
    // two A's, one B, and one C.
    //
    // tMap stores how many more times each character is still needed in the
    // current window.
    // - If tMap[ch] > 0 before taking s[j], then this character was still needed,
    //   so we reduce remaining.
    // - Then we always do tMap[ch]-- because s[j] is now inside the window.
    //   This can make the count negative, which means the window has extra copies
    //   of that character.
    //
    // remaining tells how many required characters are still missing from the
    // current window. When remaining becomes 0, the current window has all chars
    // required by t.
    //
    // Once a valid window is found, we shrink it from the left using i.
    // For each removed leftChar, we do tMap[leftChar]++ because it is no longer
    // inside the window. If tMap[leftChar] becomes positive, it means we removed
    // a character that was actually required, so the window becomes invalid and
    // remaining is increased.
    //
    // This works in O(n) time because each pointer moves only forward:
    // j expands the window, and i shrinks it. No character is processed more than
    // a constant number of times.
    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if (n1 < n2) return "";

        string ans = "";
        int minLen = INT_MAX;
        
        unordered_map<char,int> tMap;
        for(auto i: t) tMap[i]++;

        int i = 0;
        int j = 0;
        int remaining = n2;
        int start = 0;
        while(j < n1){
            char ch = s[j];

            //relevant char
            if(tMap[ch] > 0){
                remaining--;
            }

            tMap[ch]--;
            
            while(remaining  == 0) {
                int currentWindowSize = j - i + 1;
                
                // Update ans if we found a smaller valid window
                if(currentWindowSize < minLen) {
                    minLen = currentWindowSize;
                    start = i;
                }

                // Try shrinking window
                char leftChar = s[i];
                tMap[leftChar]++;
                if(tMap[leftChar] > 0) {
                    remaining++;
                }
                i++;
            }
            j++; 
        }
        if(minLen == INT_MAX) return "";
        return s.substr(start,minLen);
    }
};

int main(){
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";

    // Dry run for s = "ADOBECODEBANC", t = "ABC":
    // Required chars: A, B, C
    // Expand until "ADOBEC" contains A, B, C -> valid window, ans = "ADOBEC"
    // Shrink from left: removing A makes it invalid, so continue expanding.
    // Expand until "DOBECODEBA" contains all chars again, then shrink to "CODEBA".
    // Removing C makes it invalid, so continue expanding.
    // Expand to include final C, window becomes "ODEBANC".
    // Shrink left while valid: "DEBANC" -> "EBANC" -> "BANC".
    // "BANC" is valid and has length 4, which is the minimum.
    cout << sol.minWindow(s, t) << endl;

    return 0;
}
