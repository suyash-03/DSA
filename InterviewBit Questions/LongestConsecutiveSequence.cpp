// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(const vector<int> &A) {
if(A.size() == 0) return 0;
    vector<int> temp;
    unordered_map<int,int> myMap;
    for(int i=0; i<A.size(); i++){
        if(myMap.find(A[i]) != myMap.end()){
            continue;
        }else{
            temp.push_back(A[i]);
            myMap[A[i]]++;
        }
    }
    sort(temp.begin(),temp.end());
    int count = 1;
    int maxCount = 1;
    for(int i=0; i<temp.size()-1; i++){
        if((temp[i+1] - temp[i]) == 1){
            count++;
        }else{
            maxCount = max(maxCount,count);
            count = 1;
        }
    }
    maxCount = max(maxCount,count);
    return maxCount;
}



int main() {
    vector<int> vec = {100,4,200,1,3,2};
    int res = longestConsecutive(vec);
    cout<<res;
    return 0;
}