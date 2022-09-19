#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,list<string>> mp;
        for(int i=0; i<paths.size(); i++){
            stringstream X(paths[i]);
            string t = "";
            vector<string> path = {};
            while(getline(X,t,' ')){
                path.push_back(t);
            }
            for(int i = 1; i < path.size(); i++){
                string file = path[i];
                bool isData = false;
                unsigned first = file.find("(");
                unsigned last = file.find(")");
                string content = file.substr (first,last-first);
                mp[content].push_back(path[0]+"/"+path[i].substr(0,first));
            }
        }
        
        vector<vector<string>> result;
        for(auto it:mp){
            vector<string> temp;
            if(it.second.size() > 1){
                for(auto j:it.second){
                    temp.push_back(j);
                }
                result.push_back(temp);                
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<string> paths =  {"root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"};
    vector<vector<string>> result = s.findDuplicate(paths);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}