#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int diffPossible(vector<int> &A, int B) {
    if(A.size() == 0 || A.size() == 1) return 0;
    for(int i=0; i<A.size(); i++){
        int itemToSearch = B + A[i];
        int start = i+1;
        int end = A.size()-1;
        while(start <= end){
            int middle = (start + end)/2;
            if(A[middle] == itemToSearch){
                return 1;
            }else if(A[middle] > itemToSearch){
                end = middle - 1;
            }else{
                start = middle + 1;
            }
        }
    }
    return 0;
}

int main(){
    vector<int> temp = {1,2,3};
    int res = diffPossible(temp,0);
    cout<<"Result: "<<res<<endl;
    return 0;
}
