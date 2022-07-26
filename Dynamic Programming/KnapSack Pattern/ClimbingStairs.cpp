#include<iostream>
using namespace std;

int solveRecursion(long long nStairs,int i){
    //base case
    if(i == 0){
        return 1;
    }

    if(i < 0 ){
        return 0;
    }
    
    return(solveRecursion(nStairs,i-1) + solveRecursion(nStairs,i-2));
}

int main(){
    int res = solveRecursion(3,3);
    cout<<res;
    return 0;
}