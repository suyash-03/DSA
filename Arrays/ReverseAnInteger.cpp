#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int reverse(int A) {
    vector<int> digits;
    bool isNegative;
    if(A<0){
        isNegative = true;
    }
    int B = abs(A);
    cout<<B<<endl;
    while(B>0){
        int num = B%10;
        digits.push_back(num);
        B=B/10;
    }
    int result = 0;
    for(int i=0; i<digits.size(); i++){
        int exp = digits.size() - i -1;
        result = result + digits[i] * pow(10,exp);
        if(result > pow(2,31) - 1 || result < -(pow(2,31) - 1)) {
            return -1;
        }
    }
    if(isNegative == true){
        return -result;
    }else{
        return result;
    }   
}
int main(){
    int num = 366245711;
    int result = reverse(num);
    cout<<result<<endl;
    return 0;
}
