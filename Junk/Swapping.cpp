#include <iostream>
#include <string.h>
using namespace std;
string ans="";
int  f(int arr[][2],int dp[][1001],int n,int m,string s)
{
   // cout<<n<< " "<<m<<endl;
    if(m<0)return 0;
    if(n==-1)
    {
        if(m==0)ans=s;
        return 1;
    }
    if(dp[n][m]!=-1)return dp[n][m];
    if(ans!="")return 1;dp[n][m]=0;
    if(arr[n][0]<=m&&f(arr,dp,n-1,m-arr[n][0],"0"+s))dp[n][m]|=dp[n-1][m-arr[n][0]];
    if(arr[n][1]<=m&&f(arr,dp,n-1,m-arr[n][1],"1"+s))dp[n][m]|=dp[n-1][m-arr[n][1]];
    return dp[n][m];
} 
int find(int arr[][2],int n,int m)
{
   int dp[n][1001];
   memset(dp,-1,sizeof(dp));
   return f(arr,dp,n-1,m,"");
}
int main() {
    int t;
    cin>>t;
    while(t--){
        ans="";
   int n,m;
   cin>>n>>m;
   int arr[n][2];
   for(int i=0;i<n;i++){cin>>arr[i][0],cin>>arr[i][1];};
  if(find(arr,n,m))
  {
      cout<<"YES"<<endl;cout<<ans<<endl;
  }
  else cout<<"NO"<<endl;
    }
}