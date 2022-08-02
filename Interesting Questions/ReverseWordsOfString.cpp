#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

string solve(string A) {
    vector<string> words;

    //Removing Leading WhiteSpaces
    for(int i=0; i<A.size(); i++){
        if(A[i] == ' '){
            continue;
        }else{
            A.erase(0,i);
            break;
        }
    }

    //Remove Trailing Whitespaces
    for(int j=A.size()-1; j>0; j--){
        if(A[j] == ' '){
            continue;
        }else{
            A.erase(j+1,A.size()-1);
            break;
        }
    }
    stringstream X(A);
    string t = "";
    while(getline(X,t,' ')){
        words.push_back(t);
    }
    string result = "";
    reverse(words.begin(),words.end());
    for(int i=0; i<words.size(); i++){
        if(i != words.size()-1){
            result = result + words[i] + " ";
        }else{
            result = result + words[i];
        }
    }
    return result;
}


int main(){
    string testCase = "       fwbpudnbrozzifml osdt ulc jsx kxorifrhubk ouhsuhf sswz qfho dqmy sn myq igjgip iwfcqq                 ";
    string result = solve(testCase);
    cout<<testCase<<endl;
    cout<<result;
}