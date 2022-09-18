#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<string> deserialize(string A) {
    stringstream x(A);
    string t = "";
    vector<string> result;
    while(getline(x,t,'~')){
        result.push_back(t);
    }
    vector<string> finResult;
    for(int i=0; i<result.size(); i++){
        int sz = 0;
        string temp = result[i];
        for(int j=0; j<temp.size(); j++){
            if(temp[j] >= 48 && temp[j] <= 57){
                sz = j;
                break;
            }
        }     
        finResult.push_back(temp.substr(0,sz));
    }
    
    return finResult;
}

int main(){
    string temp = "mxxxzclaql10~omttepvukq10~sckhqgagqt10~miaufqvumh10~jndrqnllah10~wqlithzmfi10~oczafaqcrz10~lnubllvcsq10~rzngzhllmw10~ntpvbeyxnk10~";
    vector<string> result = deserialize(temp);
    for(auto it:result){
        cout<<it<<" ";
    }
    return 0;
}
