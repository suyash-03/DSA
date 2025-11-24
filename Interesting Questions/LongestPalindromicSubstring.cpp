#include <string>
using namespace std;
//Extension of the approach used in PalindromicSubstrings.cpp, we just keep track of the maximum length palindrome found so far and its indices.
//Expand around each character (for odd length palindromes) and around each pair of characters (for even length palindromes).
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        
        int maxSize = 0;
        int maxL = 0;
        int maxR = 0;
        for(int i = 0; i < n; i++){
            int l = i;
            int r = i;
            // Odd Length Palindromes
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 > maxSize){
                    maxSize = r - l + 1;
                    maxL = l;
                    maxR = r;
                }
                l--;
                r++;
            }

            l = i;
            r = i+1;
            // Even Length Palindromes
            while(l >=0 && r < n && s[l] == s[r]){
                if(r - l + 1 > maxSize){
                    maxSize = r - l + 1;
                    maxL = l;
                    maxR = r;
                }
                l--;
                r++;                
            }
        }

        for(int i = maxL; i <= maxR; i++){
            ans+= s[i];
        }
        return ans;
    }
};

int main(){
    Solution sol;
    string s = "babad";
    string result = sol.longestPalindrome(s);
    return 0;
}