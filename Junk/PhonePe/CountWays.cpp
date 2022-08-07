#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<vector<string>> allCombinations;
void subsets(int index,vector<string> studentSkills,vector<string> temp){
    if(index >= studentSkills.size()){
        if(!temp.empty()){
            for(auto i:temp){
                cout<<i<<" ";
            }
            cout<<endl;
            allCombinations.push_back(temp);
        }
        return;
    }

    temp.push_back(studentSkills[index]);
    subsets(index+1,studentSkills,temp);

    temp.pop_back();
    subsets(index+1,studentSkills,temp);
}

string twoSum(string s1,string s2){
    string res = s1;
    for(int i=0; i<s1.size(); i++){
        if(s1[i] == '0' && s2[i] == '0'){
            res[i] = '0';
        }else{
            res[i] = '1';
        }
    }
    return res;
}

string findSum(vector<string> st){
    string res = st[0];
    for(int i=0; i<st.size(); i++){
        res = twoSum(res,st[i]);
    }
    return res;
}

int numWays(vector<string> &studentSkills,string companyReq){
    vector<string> temp = {};
    allCombinations = {};
    int count = 0;
    subsets(0,studentSkills,temp);

    for(auto i:allCombinations){
        string temp = findSum(i);
        bool b = true;
        for(int i=0; i<companyReq.size(); i++){
            if(companyReq[i] == '1' && temp[i] != '1'){
                b = false;
            }
            if(companyReq[i] == '0') continue;
        }
        if(b) count++;
    }

    return count;
}

int main(){
    int x,y;
    cin>>x>>y;
    vector<string> studentSkills(x);
    for(int i=0; i<x; i++){
        cin>>studentSkills[i];
    }
    string companyReq;
    cin>>companyReq;
    int res = numWays(studentSkills,companyReq);
    cout<<res;
}