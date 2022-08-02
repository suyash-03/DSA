#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int K) {
        deque<int> dq;
        for(int i = 0; i<K; i++){
            while(!dq.empty() && arr[i] > dq.back()){
                dq.pop_back();
            }
            dq.push_back(arr[i]);
        }
        
        int start = 0;
        int end = K-1;
        int N = arr.size();
        vector<int> result;
        
        while(end <= N-1){
            result.push_back(dq.front());
            
            /* Before Incrementing start we need to make sure first element of deque is removed if it was the greatest
             because we don't need that element anymore */
             
            if(arr[start] == dq.front()){
                dq.pop_front();
            }
            start++;
            
            
            end++;
            while(!dq.empty() && arr[end] > dq.back()){
                dq.pop_back();
            }
            dq.push_back(arr[end]);

        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> vec = {1,3,-1,-3,5,3,6,7}; int k = 2;
    vector<int> res = s.maxSlidingWindow(vec,k);

    for(auto i:res){
        cout<<i<<" ";
    }

    return 0;
}