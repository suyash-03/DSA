#include <iostream>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

vector<int> maxset(vector<int> &A) {
    vector<vector<int>> sets;
    vector<int> temp;
    for(int i=0; i<A.size(); i++){
        if(A[i] >= 0){
            temp.push_back(A[i]);
        }else{
            if(!temp.empty()){
                sets.push_back(temp);
                temp.clear();
            }else{
                continue;
            } 
        }
    }
    if( !temp.empty() ) sets.push_back(temp);
    if(sets.empty()){
        return {};
    }

    long long maxSum = accumulate(sets[0].begin(),sets[0].end(),0);
    int maxLength = sets[0].size();
    int maxIndex = 0;
    for(int i=0; i<sets.size(); i++){
        for(auto j:sets[i]){
            cout<<j<<" ";
        }
        long long tempSum = 0;
        for(auto i:sets[i]){
            tempSum = tempSum + i;
        }
        if(tempSum > maxSum){
            maxSum = tempSum;
            maxLength = sets[i].size();
            maxIndex = i;
        }else if(tempSum == maxSum && sets[i].size() > maxLength){
            maxIndex = i;
            maxLength = sets[i].size();
        }
    }
    return sets[maxIndex];
}

int main(){
    vector<int> A = {756898537, -1973594324, -2038664370, -184803526, 1424268980};
    vector<int> res = maxset(A);
    for(auto it:res){
        cout<<it<<" ";
    }
    return 0;
}