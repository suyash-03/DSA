#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<char> s1;
    s1.push('a');
    s1.push('b');
    char c = s1.top();
    cout<<c;
    return 0;
}