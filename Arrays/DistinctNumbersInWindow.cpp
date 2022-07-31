#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> Nums(vector<int> &A, int B) {
    vector<int> result;
    unordered_map<int,int> myMap;
    
    for(int i=0; i<B; i++){
        myMap[A[i]]++;
    }
    
    int start = 0;
    int end = B-1;
    int N = A.size();
    
    while(end <= N-1){
        result.push_back(myMap.size());
        auto it = myMap.find(A[start]);
        it->second--;
        if(it->second == 0){
            myMap.erase(it);
        }
        start++;
        
        end++;
        if(end <= N-1) myMap[A[end]]++;
    }
    return result;
    
}

int main(){
    vector<int> temp = {1,2,1,3,4,3};
    vector<int> result = Nums(temp,3);
    cout<<"Result: "<<endl;
    for(auto i:result){
        cout<<i<<",";
    }
    return 0;
}
