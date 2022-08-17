#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void findWord(int N,string strs[]){
    string johnWord = strs[0];
    string alexWord = strs[1];

    unordered_map<int,char> alexMap;
    for(int i=0; i<alexWord.size(); i++){
        alexMap[i] = alexWord[i];
    }

    sort(johnWord.begin(),johnWord.end());
    
    vector<string> res;
    do{
        bool isLex = true;
        for(int i=0; i<johnWord.size(); i++){
            if(alexMap[i] == johnWord[i]){
                isLex = false;
                break;
            }
        }
        if(isLex){
            res.push_back(johnWord);
        }

    }while(next_permutation(johnWord.begin(),johnWord.end()));
    
    sort(res.begin(),res.end());
    cout<<res[0];
}

int main(){
    int n;
    cin>>n;
    string strs[n];
    for(int i=0; i<2; i++){
        cin>>strs[i];
    }
    findWord(n,strs);
    return 0;
}