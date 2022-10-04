#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(int i,int j,vector<int>&a,vector<vector<int>>&dp)
    {
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        int ans=INT_MIN;
        
        for(int idx=i;idx<=j;idx++)
        {
            int cost=a[i-1]*a[idx]*a[j+1]+solve(i,idx-1,a,dp)+solve(idx+1,j,a,dp);
            ans=max(ans,cost);
        }
        return dp[i][j]=ans;
    }
    
    
    int maxCoins(vector<int>&a) {
        int n=a.size();
        a.push_back(1);
        a.insert(a.begin(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,a,dp);
    }

    int main(){
        vector<int> a = {3,1,5,8};
        int res = maxCoins(a);
        cout<<res;
        return 0;
    }

