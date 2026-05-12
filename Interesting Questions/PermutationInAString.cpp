#include <bits/stdc++.h>
using namespace std;
/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false

*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if(n1 > n2) return false;

        unordered_map<char,int> freq1;
        for(auto i: s1){
            freq1[i]++;
        }

        unordered_map<char,int> freq2;
 

        for(int k = 0; k <= n1-1; k++){
            freq2[s2[k]]++;
        }

        int i = 0;
        int j = n1-1;
        while(j < n2){
            if(freq1 == freq2) return true;
            
            j++;
            freq2[s2[j]]++;
           
            freq2[s2[i]]--;
            if(freq2[s2[i]] == 0) freq2.erase(s2[i]);
            i++;
        }

        return false;
    }
};