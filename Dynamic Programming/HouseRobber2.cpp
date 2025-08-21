#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int utilA(int n, vector<int> &money, vector<int> &dpA){
        if(n <= 1){
            return 0;
        }
        if(dpA[n] != -1){
            return dpA[n];
        }

        return dpA[n] = max(money[n-1] + utilA(n-2, money, dpA), utilA(n-1, money, dpA));
    }

    int utilB(int n, vector<int> &money, vector<int> &dpB){
        if(n <= 0){
            return 0;
        }
        if(dpB[n] != -1){
            return dpB[n];
        }

        return dpB[n] = max(money[n-1] + utilB(n-2, money, dpB), utilB(n-1, money, dpB));
    }

    int utilC(int n, vector<int> &money, vector<int> &dpC){
        if(n <= 0){
            return 0;
        }
        if(dpC[n] != -1){
            return dpC[n];
        }

        return dpC[n] = max(money[n-1] + utilC(n-2, money, dpC), utilC(n-1, money, dpC));
    }
    
    int houseRobber(vector<int>& money) {
        int n = money.size();
        vector<int> dpA(n+1, -1);
        vector<int> dpB(n+1, -1);
        vector<int> dpC(n+1, -1);
        // Last Home is Robbed and First Home can't be Robbed
        int a = money[n-1] + utilA(n-2,money,dpA);
        
        // Second Last Home is Robbed so First Home can be Robbed
        int b = money[n-2] + utilB(n-3,money,dpB);
        
        // Neither Last or Second Last Home is Robbed
        int c = utilC(n-2, money, dpC);

        return max(c, max(a,b));
    }
};

int main(){
    Solution sol;
    vector<int> money = {2, 3, 2};
    cout << sol.houseRobber(money) << endl;
    return 0;
}