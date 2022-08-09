#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    bool isPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
    void backtrack(int index,string s,vector<string> temp){
        if(index >= s.size()){
            res.push_back(temp);
            return;
        }
        for(int j=index; j<s.size(); j++){
            if(isPalindrome(s,index,j) == true){
                temp.push_back(s.substr(index,j-index+1));
                backtrack(j+1,s,temp);
                temp.pop_back();
            } 
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<string> temp = {};
        backtrack(0,s,temp);
        return res;
    }
};