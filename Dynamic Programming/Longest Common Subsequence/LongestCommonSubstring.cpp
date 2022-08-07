#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int lcs(string text1,string text2,int n,int m,int count,unordered_map<string,int> &myMap){
        if(n <= 0 || m <= 0){
            return count;
        }
        string key = to_string(n) + " " + to_string(m) + "-" + to_string(count);
        if(myMap.find(key) != myMap.end()){
            return myMap[key];
        }
        int same = count;
        if(text1[n-1] == text2[m-1]){
            same = lcs(text1,text2,n-1,m-1,count+1,myMap);
        }
        int diff1 = lcs(text1,text2,n,m-1,0,myMap);
        int diff2 = lcs(text1,text2,n-1,m,0,myMap);
        int res = max(same,max(diff1,diff2));
        myMap[key] = res;
        return res;
    }
    
    int longestCommonSubstr (string text1, string text2, int n, int m)
    {
        // your code here
        unordered_map<string,int> myMap;
        return lcs(text1,text2,n,m,0,myMap);
    }
};

int main(){
    Solution s;
    int res = s.longestCommonSubstr("pqrs","abpq",4,4);
    cout<<res<<endl;
}