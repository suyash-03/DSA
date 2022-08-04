#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxGold(vector<int> &gold,int k){
    int n = k;
    int maxSum = 0;
    while(n>0){
        int rightSum = 0;
        int leftSum = 0;

        //Right Sum
        for(int i=0; i<n; i++){
            rightSum = rightSum + gold[i];
        }
        
        //Left Sum
        for(int i=gold.size()-1; i > (gold.size() -1 - (k-n)); i--){
            leftSum = leftSum + gold[i];
        }

        maxSum = max(leftSum+rightSum,maxSum);
        n--;
    }
    return maxSum;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> gold(n);
    for(int i=0; i<gold.size(); i++){
        cin>>gold[i];
    }

    int res = maxGold(gold,k);
    cout<<res;
}