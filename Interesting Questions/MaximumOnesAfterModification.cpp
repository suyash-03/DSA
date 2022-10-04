#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int solve(vector<int> &A, int B) {
    int numOnes = 0;
    int numZeros = 0;
    int N = A.size();
    
    for(int i=0; i<A.size(); i++){
        if(A[i] == 1) numOnes++;
        else numZeros++;
    }
    
    if(numZeros <= B) return A.size();
    
    int start = 0;
    int end = numOnes-1;
    int width = numOnes;
    cout<<"Width: "<<width<<endl;
    int countZeros = 0;
    for(int i=0; i<=end; i++){
        if(A[i] == 0) countZeros++;
    }
    int ans = 0;
    while(end < N){
        for(int i = start ; i <= end; i++){
            cout<<A[i]<<" ";
        }
        cout<<"---"<<countZeros<<" ";
        int res = width + B - countZeros;
        cout<<"--->"<<res<<endl;
        ans = max(res,ans);
        start++;
        if(A[start-1] == 0){
            countZeros--;
        }
        end++;
        if(A[end] == 0){
            countZeros++;
        }
    }
    // cout<<endl;
    return ans;
}

int main(){
    vector<int> temp = {1,1,1,0,0,0,1,1,1,1,0};
    for(auto it:temp){
        cout<<it<<" ";
    }
    cout<<endl;
    int res = solve(temp,2);
    cout<<res;
    return 0;
}
