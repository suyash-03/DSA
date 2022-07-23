#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define f(i,a,n,b) for(int i = a;i<n;i+=b)
#define sz(x) ((int)(x).size()) 
#define pb push_back
#define F first
#define S second
const ll mxN = 2e5, mod = 1e9+7;
const ll INF = 1e18;
vector<vector<int>>dp;
int dfs(int i, int mask,vector<int>&arr,int k)
{
  if(i == arr.size())
  {
    return 0;
  }
  if(dp[i][mask] != -1)
  {
    return dp[i][mask];
  }
  int ans = 0;
  int prevmask = mask;
  for(int j = 0;j<k;j++)
  {
      if(prevmask%3 <= 1)
      {
        int mask1 = mask +  pow(3,j);
        ans = max(ans , ((j+1)&(arr[i])) + dfs(i+1,mask1,arr,k));
      }  
      prevmask/=3;
  }
  return dp[i][mask] = ans;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {  
      int n,k;
      cin>>n>>k;
      vector<int>arr(n);
      for(int i = 0;i<n;i++)
      {
        cin>>arr[i];
      }
      int value = pow(3,k)+3;
      dp.resize(n,vector<int>(value,-1));
      cout<<dfs(0,0,arr,k)<<"\n";
    }
    return 0;
}