// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
#include<utility>
using namespace std;

class Solution {
public:
    int res = 0;
    set<vector<int>> st;
    void recursion(vector<int> &coins,int currentAmount,vector<int> temp){
        if(currentAmount == 0){
            sort(temp.begin(),temp.end());
            st.insert(temp);
        }
        for(auto coin:coins){
            if(currentAmount - coin >= 0){
                cout<<"(Current Amount): "<<currentAmount<<" - (Coin): "<<coin<<"  (Result): "<<currentAmount-coin<<endl;
                temp.push_back(coin);
                recursion(coins,currentAmount - coin,temp);
            }else{
                temp.clear();
            }
        }
    }
    int change(int amount, vector<int>& coins) {
        vector<int> temp;
        recursion(coins,amount,temp);
        return st.size();
    }
};

int main() {
    Solution s;
    vector<int> coins = {1,2};
    int ans = s.change(15,coins);
    cout<<"Answer: "<<ans;
    return 0;
}