#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//If starting from S gives me enough gas to reach every station up to i, but I finally go negative at i, then every station between S and i has an even smaller "remaining journey" budget and therefore cannot be a valid start.
// If the total amount of gas is greater than the total amount of cost, there must be a solution. The greedy algorithm is to start from station 0 and keep track of the remaining gas. If at any point the remaining gas becomes negative, we know that we cannot reach station i from station 0, so we set the next station as the new starting point and reset the remaining gas to 0. We continue this process until we have checked all stations. The last starting point will be the answer.
class Solution {
public:
    //Greedy Algorithm
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(gas.begin(),gas.end(),0) < accumulate(cost.begin(),cost.end(),0)){
            return -1;
        }
        int n = gas.size();
        int total = 0;
        int res = 0;
        for(int i=0; i<n; i++){
            total += gas[i]-cost[i];
            if(total < 0){
                total = 0;
                res = i+1;
            }
        }
        return res;
    }
};