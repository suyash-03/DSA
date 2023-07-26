#include<iostream>
#include<vector>
#include<string>

/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

*/


class Solution {
public:
    string reverseWords(string s) {
        int start = s.find_first_not_of(' ');
        int end = s.find_last_not_of(' ');
        string str = s.substr(start,(end-start+1));
        
        vector <string> tokens;
        stringstream ss(str);
        string temp;
        
        while (ss >> temp) {
            tokens.push_back(temp);
        }

        string ans;
        reverse(tokens.begin(),tokens.end());
        for(int i=0; i < tokens.size(); i++){
            if(i == tokens.size()-1){
                ans = ans + tokens[i];
            }else{
                ans =  ans + tokens[i] + " ";
            }
        }

        return ans;
    }
};