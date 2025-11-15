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
        unordered_map<char,int> myMap1;

        int n2 = s2.size();
        unordered_map<char,int> myMap2;
        
        if(n2 < n1) return false;

        for(auto c:s1){
            myMap1[c]++;
        }

        for(int i = 0; i < n1; i++){
            myMap2[s2[i]]++;
        }

        if(myMap1 == myMap2) return true;

        for(int i = n1; i < n2; i++){
            myMap2[s2[i]]++;
            myMap2[s2[i-n1]]--;

            if(myMap2[s2[i-n1]] == 0){
                myMap2.erase(s2[i-n1]);
            }

            if(myMap2 == myMap1){
                return true;
            }
        }
        return false;       
    }
};