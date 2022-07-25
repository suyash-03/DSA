#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dfs(int n,vector<int> &vec){
    if(n == 0 || vec[n-1] == 0){
        return 0;
    }
    if(vec[n-1] >= 0){
        vec[n-1]--;
        return max(1 + dfs(n-1,vec),dfs(n,vec));
    }else{
        return dfs(n,vec);
    }
    
}

int maxMedicalCentres(int n,vector<int> &vec){
    return maxMedicalCentres(n-1,vec);
}
int main(){
    int numCity;
    cin>>numCity;
    vector<int> locations(numCity);
    for(int i=0; i<numCity; i++){
        cin>>locations[i];
    }
    int res = maxMedicalCentres(numCity,locations);

}