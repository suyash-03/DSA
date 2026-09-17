#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
    public:
        string encode(vector<string>& strs) {
            string encoded_string = "";

            int n = strs.size();
            for(int i = 0; i < n; i++){
                string currentEncodedWord = to_string(strs[i].size()) + '#' + strs[i];
                encoded_string += currentEncodedWord;
            }

            return encoded_string;
        }

        vector<string> decode(string s) {
            int n = s.size();
            vector<string> words;

            //5#Hello5#World
            int i = 0;
            while(i < s.size()){
                int j = i;
                while(s[j] != '#') j++;
                int len = stoi(s.substr(i, j-i));
                
                int start = j + 1;
                words.push_back(s.substr(start, len));
                i = start + len;
            }
            return words;
        }
};



int main() {
    Solution solution;
    vector<string> strs = {"Hello", "World"};
    string encoded = solution.encode(strs);
    cout << "Encoded string: " << encoded << endl;  
    vector<string> decoded = solution.decode(encoded);
    cout << "Decoded strings: ";
    for (const auto& str : decoded) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}