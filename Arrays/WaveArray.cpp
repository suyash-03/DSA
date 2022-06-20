#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// wave vector - a1 >= a2 <= a3 >= a4 .......
vector<int> wave(vector<int> &A) {
    sort(A.begin(),A.end());
    int temp;
    for(int i=0;i<A.size()-1; i++){
        if(i%2 == 0){
            int temp = A[i];
            A[i] = A[i+1];
            A[i+1] = temp;
        }
    }
    return A;
}

int main(){
    vector<int> A;
    vector<int> result;
    A.push_back(5);
    A.push_back(1);
    A.push_back(3);
    A.push_back(2);
    A.push_back(4);
    result = wave(A);
    return 0;
}