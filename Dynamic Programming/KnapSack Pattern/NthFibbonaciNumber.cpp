#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Top Down Approach - Recursion + Memoization 0(n) time 0(n) space
class Solution {
public:
    unordered_map<int,int> myMap;
    int fib(int n) {
        if( n==0 || n==1 ){
            return n;
        }else if( myMap.count(n) == 1){
            return myMap[n];
        }else{
            myMap[n] = fib(n-1) + fib(n-2);
        }
        return myMap[n];
    }
};

//Bottom Up Approach - 0(n) time, 0(n) space
class Solution2{
public:
    unordered_map<int,int> myMap;
    int fib(int n) {
        myMap[0] = 0;
        myMap[1] = 1;
        for(int i=2 ; i<=n ; i++){
            myMap[i] = myMap[i-1] + myMap[i-2];
        }
        return myMap[n];
    }
};

//DP Bottom Up - Space Optimised Solution - o(n) time 0(1) space
class Solution3 {
public:
    int fib(int n) {
        int prev2 = 0;
        int prev1 = 1;
        if(n == 0 ) return 0;
        for(int i=2 ; i<=n ; i++){
            int current = prev2 + prev1;
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};



int main(){
    Solution s1;
    int result  = s1.fib(44);
    cout<<result;
    return 0;
}
