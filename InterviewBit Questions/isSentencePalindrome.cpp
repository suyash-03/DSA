#include<iostream>
#include<vector>
using namespace std;
int isPalindrome(string A) {
    vector<char> vec;
    for(int i=0; i<A.length(); i++){
        if(A[i] >= 65 && A[i] <= 90){
            vec.push_back(A[i] + 32);
        }else if(A[i] >= 97 && A[i] <= 122){
            vec.push_back(A[i]);
        }else if(A[i] >= 48 && A[i] <= 57){
            vec.push_back(A[i]);
        }else{
            continue;
        }
    }
    
    int i = 0;
    int j = vec.size()-1;
    while(i<j){
        if(vec[i] != vec[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}
int main(){
    string A ="1a2";
    int result = isPalindrome(A);
    cout<<result;
}
