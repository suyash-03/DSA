#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freqMap;
        int maxFreq = 0;

        int i = 0;
        int j = 0;
        int n = s.size();
        int ans = 0;

        while(j < n){
            freqMap[s[j]]++;

            maxFreq = max(maxFreq, freqMap[s[j]]);

            if((j-i+1) - maxFreq  > k){
                freqMap[s[i]]--;
                i++;
            }
            ans = max(j-i+1, ans);
            j++;

        }

        return ans;
    }
};

int main(){
    Solution sol;
    string s = "AABABBA";
    int k = 1;

    cout << sol.characterReplacement(s, k) << endl;

    return 0;
}
