#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> funcDistance(vector<int> inputDist,int start,int end){
    vector<int> ans;
    int t;
    for(int i=0; i<inputDist.size(); i++){
        if(inputDist[i] < 0){
            t =-inputDist[i];  
        }else{
            t = inputDist[i];
        }

        if(t >=start && t <= end){
            ans.push_back(t);
        }
    }

    return ans;
}

int main(){
    int inputDist_size;
    cin>>inputDist_size;
    vector<int> inputDist;
    for(int idx = 0; idx < inputDist_size; idx++){
        int temp;
        cin>>temp;
        inputDist.push_back(temp);
    }

    int start;
    cin>>start;

    int end;
    cin>>end;

    vector<int> result = funcDistance(inputDist,start,end);
    for(int idx = 0; idx < result.size()-1; idx++){
        cout<<result[idx]<<" ";
    }
    cout<<result[result.size()-1];
    return 0;
}