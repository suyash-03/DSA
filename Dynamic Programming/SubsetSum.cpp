#include<bits/stdc++.h> 
using namespace std; 

//2D DP Memoisation
class Solution{   
public:
    bool dfs(int n,int sum,vector<int> arr,vector<vector<int>> &dp){
        if(sum == 0){
            return true;
        }
        if(n <= 0){
            return false;
        }
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        
        
        if(arr[n-1] <= sum){
            return dp[n][sum] = ( dfs(n-1,sum-arr[n-1],arr,dp) || dfs(n-1,sum,arr,dp) );
        }else{
            return dp[n][sum] = dfs(n-1,sum,arr,dp);
        }
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n =arr.size();
        vector<vector<int>> dp(n+1,vector<int> (sum+1, -1));
        return dfs(n,sum,arr,dp);
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
