#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int calculateDiscount(int billAmount){
    int answer;

    vector<int> nums;
    while(billAmount > 0){
        int r = billAmount%10;
        billAmount = billAmount/10;
        nums.push_back(r);
    }

    int sum = 0;
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] %2 == 1){
            sum = sum +nums[i];
        }
    }
    answer = sum;
    return answer;
}

int main(){
    int billAmount;
    cin>>billAmount;
    int result = calculateDiscount(billAmount);
    cout<<result;
    return 0;
}