#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;    

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int i = 0;
        int j = 1;
        int n = s.size();
        int ans = 1;

        unordered_set<char> st;
        st.insert(s[0]);

        while(i < n && j < n){
            if(st.find(s[j]) == st.end()){
                st.insert(s[j]);
                ans = max(ans, j - i + 1);
                j++;
            }else{
                st.erase(s[i]);
                i++;
            }
        }
        return ans;

    }
};