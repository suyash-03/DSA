#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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

// O(N^2)
class Solution2{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int currentGas = 0;
        for(int i=0; i<n; i++){
            currentGas = gas[i];
            int stop = i;
            bool round = false;
            while(1){
                currentGas = currentGas - cost[stop];
                if(stop == i && currentGas >= 0 && round){
                    return i;
                }
                if(currentGas < 0 ){
                    break;
                }
                stop = (stop+1)%n;
                round = true;
                currentGas = currentGas + gas[stop];
            }
        }
        return -1;
    }
};