// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[], long long int N, long long int K) {
    
    vector<long long> result;
    queue<long long> q;
    int start = 0;
    int end = K - 1;
    
    for(int i=0; i<K; i++){
        if(arr[i] < 0){
          q.push(arr[i]);  
        } 
    }
    
    while(end <= N-1){
        if(q.empty()){
            result.push_back(0);
            start++;
            end++;
            if(arr[end] < 0){
                q.push(arr[end]);
            }
        }else{
            result.push_back(q.front());
            if(arr[start] < 0){
                q.pop();
            }
            start++;
            end++;
            if(arr[end] < 0){
                q.push(arr[end]);
            }   
        }
    }
    
    return result;
 }

int main() {
    long long int arr[] = {-8,2,3,-6,10};
    vector<long long> res = printFirstNegativeInteger(arr,5,2);
    for(auto i:res){
        cout<<i<<" ";
    }
    return 0;
}