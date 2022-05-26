#include<iostream>
#include<stack>
#include<stdio.h>
#include <cstdlib>
#include<string.h>
#include<vector>
#include<sstream>

using namespace std;

vector<string> split(string s,char delimiter){
    vector<string> tokens;
    string token;
    stringstream ss(s);

    while(getline(ss,token,delimiter)){
        tokens.push_back(token);
    }    
    return tokens;
}

void EvaluatePostfix(vector<string> str){
    stack<int> s1;
    cout<<"Reading from string \n";
    for(int i=0 ; i< str.size(); i++){
        if(str[i] != "+" && str[i] != "-" && str[i] != "*" && str[i] != "/"){
            //stoi converts string to integer
            cout<<"Now Parsed:  "<<stoi(str[i])<<"\n";
            s1.push(stoi(str[i]));
        } else {
            //we encounter an operator
            string optr  = str[i];
            int operand2 = s1.top();
            s1.pop();
            int operand1 = s1.top();
            s1.pop();
            cout<<"Now Performing: "<<operand1<<" "<<optr<<" "<<operand2<<"\n";
            if(optr == "+"){
                s1.push(operand1+operand2);
            } else if(optr == "-"){
                s1.push(operand1-operand2);
            } else if(optr == "*"){
                s1.push(operand1*operand2);
            } else if(optr == "/"){
                s1.push(operand1 / operand2);
            }
        }
    }

    cout<<"Result: "<<s1.top()<<"\n";
}

int main(){
    cout<<"Remember to separate operators and operands by a space \n";
    cout<<"Enter a Postfix Expression to be evaluated: \n";
    char str[51];
    gets(str);
    vector<string> finalString = split(str,' ');
    EvaluatePostfix(finalString);
    return 0;
}