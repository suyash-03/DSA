#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans  = 0;
        for(int i = 0 ; i < n; i++){
            // Odd Length Palindromes with s[i] as the center
            int l = i;
            int r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                ans++;
                l--;
                r++;
            }

            // Even Length Palindromes with s[i] and s[i+1] as the center
            l = i;
            r = i+1;
            while(l >= 0 && r < n && s[l] == s[r]){
                ans++;
                l--;
                r++;
            }
        }

        return ans;
    }
};

int main(){
    Solution sol;
    string s = "aaa";
    int result = sol.countSubstrings(s);
    return 0;
}