// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int lastDigitKCount(int A,int B,int C){
    //Get to first Number with last Digit C
    while(A <= B && A%10 != C) A++;
    if(A>B) return 0;
    int n = (B-A)/10 + 1;
    return n;
}

int main() {

    int result = lastDigitKCount(11,121,1);
    cout<<result;
    return 0;
}
