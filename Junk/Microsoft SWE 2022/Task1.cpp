#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int splitString(string str){
    unordered_map<char,int> myMap;
    for(int i=0; i<str.size(); i++){
        myMap[str[i]]++;
    }
    int n = str.size();
    int count = 0;
    while(n > 0){
        count = count+1;
        for(auto it: myMap){
            if(it.second > 0){
                it.second--;
                n--;
            }
        }
    }
    return count;
}

int main(){
    int res = splitString("world");
    cout<<res<<endl;
    return 0;
}