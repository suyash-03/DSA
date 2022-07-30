//Sliding Window Problem


#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &arr , int N){
        // code here 
        long long r = 0;
        
        for(int i=0; i < K ; i++){
            r = r + arr[i];
        }
        
        int start = 0;
        int end = K-1;
        long long res = r;
        while(end <= N-1){
            res = max(res,r);
            start++;
            end++;
            r = r + arr[end];
            r = r - arr[start-1];
        }
        
        return res;
    }
};

int main(){
  return 0;
}
