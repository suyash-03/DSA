#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int> v1,vector<int> v2){
        if(v1[0] == v2[0]){
            return v1[1] > v2[1];
        }
        else return v1[0] < v2[0];
    }
    int dfs(int curr,int prev,vector<vector<int>> &ev,vector<vector<int>> &dp){
        if(curr >= ev.size()){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        if(prev == -1 || (ev[curr][0] > ev[prev][0] && ev[curr][1] > ev[prev][1] ) ){
            return dp[curr][prev+1] = max(1 + dfs(curr+1,curr,ev,dp),dfs(curr+1,prev,ev,dp));
        }else{
            return dp[curr][prev+1] = dfs(curr+1,prev,ev,dp);
        }
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        int n = envelopes.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return dfs(0,-1,envelopes,dp);
    }
};
//Based on LIS Pattern
class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
        
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        int i, j, n=envelopes.size();
        vector<int>lis;
        
        for(i=0; i<n; i++){
            auto it = lower_bound(lis.begin(), lis.end(), envelopes[i][1]);
            if(it==lis.end()){lis.push_back(envelopes[i][1]);}
            else{
                *it = envelopes[i][1];
            }
        }
        return lis.size();
    }
};