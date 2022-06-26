#include<iostream>
using namespace std;

int sqrt(int A) {
    long long start = 0;
    long long end = A;
    long long middleToReturn = 0;
    while(start <= end){
        long long middle = (start+end)/2;
        middleToReturn = middle;
        long long square = middle*middle;
        if(square == A){
            return middle;
        }
        else if(square < A){
            start = middle + 1;
        }else{
             end =  middle - 1;
        }
    }
    if(start*start < A) return start;
    else if(middleToReturn * middleToReturn < A) return middleToReturn;
    else return end;
}


int main(){
    int a = 11;
    int result = sqrt(2147483647);
    cout<<result;
    return 0;
}