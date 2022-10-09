#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char findExtraLetter(string &A, string &B){
    unordered_map<char,int> aMap;
    for(int i=0; i<A.size(); i++){
        aMap[A[i]]++;
    }

    char toReturn;
    for(int i=0; i<B.size(); i++){
        if(aMap.find(B[i]) == aMap.end()){
            toReturn = B[i];
        }
    }
    return toReturn;
}

int main(){
    string a = "cocubes";
    string b = "ocucybse";

    char res =  findExtraLetter(a,b);
    cout<<res;
}