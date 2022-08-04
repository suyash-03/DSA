#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int countPlus(vector<string> operators){
    int num = 0;
    for(int i=0; i<operators.size(); i++){
        if(operators[i] == "+"){
            num++;
        }
    }
    return num;
}
int countMinus(vector<string> operators){
    int num = 0;
    for(int i=0; i<operators.size(); i++){
        if(operators[i] == "-"){
            num++;
        }
    }
    return num;
}

static bool cmpDescending(string s1,string s2){
    int a = stoi(s1);
    int b = stoi(s2);
    return a>b;
}

static bool cmpAscending(string s1,string s2){
    int a = stoi(s1);
    int b = stoi(s2);
    return a<b;
}

int maxOrminInteger(vector<string> &digits,vector<string> &operators,bool max){
    int numPlus = countPlus(operators);
    int numMinus = countMinus(operators);
    int numMinusCopy = numMinus;
    int numPlusCopy = numPlus;

    int n = digits.size();
    if(max == true){
        sort(digits.begin(),digits.end(),cmpDescending);
    }else{
        sort(digits.begin(),digits.end(),cmpAscending);
    }
    
    vector<int> numbers;
    while(numMinus > 0){
        string s = digits[n-numMinus];
        int num = stoi(s);
        numbers.push_back(0-num);
        numMinus--;
    }

    while(numPlus > 0){
        string s = digits[n-numMinusCopy-numPlus];
        int num = stoi(s);
        numbers.push_back(num);
        numPlus--;
    }

    string mainNum = "";
    for(int i=0; i<n-numPlusCopy-numMinusCopy; i++){
        mainNum = mainNum + digits[i];
    }
    
    numbers.push_back(stoi(mainNum));

    return accumulate(numbers.begin(),numbers.end(),0);
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        vector<string> digits(n);
        for(int i=0; i<digits.size(); i++){
            cin>>digits[i];
        }
        int op;
        cin>>op;
        vector<string> operators(op);
        for(int i=0; i<operators.size(); i++){
            cin>>operators[i];
        }
        int maxi = maxOrminInteger(digits,operators,true);
        int mini = maxOrminInteger(digits,operators,false);
        cout<<maxi<<" "<<mini<<endl;
        t--;
    }
    return 0;
}