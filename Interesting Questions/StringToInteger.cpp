#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

int myAtoi(string s) {
        queue<char> vec1;
        int len = s.length();
        for(int i=0 ; i<len; i++){
            if(s[i] == '1' ||s[i] == '2' || s[i] == '3' ||
               s[i] == '4' ||s[i] == '5' || s[i] == '6' ||
               s[i] == '7' ||s[i] == '8' || s[i] == '9' || 
               s[i] == '0' ||s[i] == '+' || s[i] == '-'){
                vec1.push(s[i]);
            }
             if( !vec1.empty() && s[i] == ' '){
                break;
            }
        }
        if(vec1.front() == '0'){
        while(vec1.front() != '0'){
            vec1.pop();
        }
        }
        char sign;
        if(vec1.front() == '+' || vec1.front() == '-'){
           sign = vec1.front();  
           vec1.pop();
        }else{
            sign = '+';
        }
        int result = 0;
        int lengthOfNumber = vec1.size();
        for(int i=0; i<lengthOfNumber; i++){
            char c[] = {vec1.front()};
            int num = atoi(c);
            result = result + (num*pow(10,lengthOfNumber-i-1));
            vec1.pop();
            c[0] = {'\0'};
        }
        if(sign == '+'){
            return result;
        }else{
            return -result;
        }
        
    }



int main(){
    string s ="  -4264 12 with words";
    int result = myAtoi(s);
    cout<<result;
    return 0;
}