#include <iostream>
#include <bits/stdc++.h>
using namespace std;


long getMaxAggeregateTemperatureChange(vector<int> tempChange){
    vector<long long> tempChangesPerDay;
    int n = tempChange.size();
    vector<long long> prefixSum(n,0);
    vector<long long> suffixSum(n,0);


    prefixSum[0] = tempChange[0];
    for(int i=1; i<n; i++){
        prefixSum[i] = prefixSum[i-1] + tempChange[i];
    }

    suffixSum[n - 1] = tempChange[n - 1];
    for (int i = n - 2; i >= 0; i--){
        suffixSum[i] = suffixSum[i + 1] + tempChange[i];
    }

    for(int i=0; i<n; i++){
        long long r = max(prefixSum[i],suffixSum[i]);
        tempChangesPerDay.push_back(r);
    }

    long long result = *max_element(tempChangesPerDay.begin(),tempChangesPerDay.end());
    return result;
}

int main(){
    vector<int> test = {6,-2,5};
    int res = getMaxAggeregateTemperatureChange(test);
    cout<<res;
    return 0;
}