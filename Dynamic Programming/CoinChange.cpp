#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int dp[10010];
    int recursion(vector<int> &coins,int current){
        int ans = INT_MAX;
        if(current == 0){
            return 0;
        }
        if(dp[current] != -1) return dp[current];    
            for(auto coin: coins){
                if(current-coin >= 0){
                ans = min(ans + 0LL,recursion(coins,current-coin) + 1LL);
                }
            }                
        return dp[current]=ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int res = recursion(coins,amount);

        return res == INT_MAX ? -1 : res;
    }
};

int main(){
    Solution s;
    vector<int> v = {3};
    int res = s.recursion(v,2);
    cout<<res;
}