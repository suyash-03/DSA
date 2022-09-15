#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lcs(string &text1, string &text2,int n,int m,vector<vector<int>> &dp){
    if(m==0 or n==0) return 0;

    if(dp[m][n] != -1){
        return dp[m][n];
    }

    if(text1[m-1] == text2[n-1]){
        return dp[m][n] = (1 + lcs(text1,text2,n-1,m-1,dp));
    }

    return dp[m][n] = max(lcs(text1,text2,n-1,m,dp),lcs(text1,text2,n,m-1,dp));
}


int findMinimumCharacters(string searchWord, string resultWord){
    int m = searchWord.size();
    int n = resultWord.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int len = lcs(searchWord,resultWord,n,m,dp);
    
    string temp = ""; 
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (searchWord[i - 1] == resultWord[j - 1]) {
            temp += (searchWord[i - 1]);
            i--;
            j--;
        }
 
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    
    reverse(temp.begin(),temp.end());
    for(int i=0; i<temp.size(); i++){
        if(temp[i] != resultWord[i]){
            return resultWord.size();
        }
    }
    return resultWord.size() - len; 
}

int main() {
    int res = findMinimumCharacters("armaze","amazon");
    cout<<res;
    return 0;
}