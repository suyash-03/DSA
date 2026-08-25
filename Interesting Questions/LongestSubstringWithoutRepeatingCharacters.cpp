#include <bits/stdc++.h>
#include <unordered_set>
#include <set>
using namespace std;    

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int ans = 0;
        int n = s.size();
        
        set<char> st;
        int i = 0;
        int j = 0;

        while(j < n){
            if(st.find(s[j]) != st.end()){
                st.erase(s[i]);
                i++;
            }else{
                st.insert(s[j]);
                j++;
            }
            ans = max(ans, j-i);
        }

        return ans;
    }
};