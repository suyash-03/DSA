#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool checkIfPalindrome(string str){
    int i=0;
    int j = str.size()-1;
    while(i<=j){
        if(str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}
int solve(string A) {
    vector<string> words;
    int count = 0;
    string T;
    stringstream X(A); // X is an object of stringstream that references the S string  
   
    // use while loop to check the getline() function condition  
    while (getline(X, T, ' ')) {  
        /* X represents to read the string from stringstream, T use for store the token string and, 
         ' ' whitespace represents to split the string where whitespace is found. */  
          if(checkIfPalindrome(T) == true) count++;   
    } 
    return count;
}


int main(){
    string s = "wow mom";
    int res = solve(s);
    cout<<res;
}