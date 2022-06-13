/*
int length = A.size();
    cout<<"The length is: "<<length;
    cout<<"\n";
    if(A[length-1] != 9){
        cout<<"Last Digit Not 9 \n";
      A[length-1] = A[length-1] + 1;
      return A;   
    }
  else if(A[length-1]  == 9){
         int j = length -1;
        while((A[j]+1)%10 == 0){
            if(j == 0){
                cout<<"Inside j =0 ";
                cout<<"\n";
                A[0] = (A[0]+1)%10;
                A.insert(A.begin(),1);
            } else{
                A[j] = (A[j]+1)%10;
                
            }
            j =  j-1;  
        }
    }
    return A;
    */

#include<iostream>
#include<vector>
#include<math.h>
 
#include <bits/stdc++.h>
using namespace std;

vector<int> plusOneBruteForce(vector<int> &A) {
    int length = A.size();
    unsigned long long int number = 0;
    for(int i=0; i<length;i++){
        number = number + (A[i]*pow(10,length-i-1));
    }
    unsigned long long int sol = number + 1;
    vector<int> solution;
    while(sol != 0){
        int r = sol%10;
        cout<<"\n";
        solution.push_back(r);
        sol = sol/10;
    }
    
    reverse(solution.begin(),solution.end());
    return solution;

}

vector<int> plusOne(vector<int> &digits) {
     reverse(digits.begin(), digits.end());
            vector<int> ans;
            int carry = 1;
            for (int i = 0; i < digits.size(); i++) {
                int sum = digits[i] + carry;
                ans.push_back(sum%10);
                carry = sum / 10;
            }
            while (carry) {
                ans.push_back(carry%10);
                carry /= 10;
            }
            //Removing extra 0 at start
            while (ans[ans.size() - 1] == 0 && ans.size() > 1) {
                ans.pop_back(); 
            }
            reverse(ans.begin(), ans.end());
            
            return ans;
}

int main(){
    vector<int> A;
    for(int i=0; i<9; i++){
        A.push_back(9);
    }
    vector<int> solution = plusOneBruteForce(A);
    cout<<"\n";
    vector<int> actualSolution = plusOne(A);
    
    for(int j=0;j<solution.size(); j++){
        cout<<solution[j]<<" ";
    }

}