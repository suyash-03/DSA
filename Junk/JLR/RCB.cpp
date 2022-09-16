#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> dp = {25,1,0};
    for(int i=0; i<n-1; i++){
        long long a = dp[0]*25 + dp[1]*24 + dp[2]*24;
        long long b = dp[0]+dp[1]+dp[2];
        long long c = dp[1];
        dp[0] = a; dp[1] = b; dp[2] = c;
    }
    int mod = pow(10,9)+7;
    long long sum = 0;
    for(int i=0; i<dp.size(); i++){
        sum = sum + dp[i];
    }
    cout<<sum%mod;
    return 0;
}