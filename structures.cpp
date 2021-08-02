#include <iostream>
#include <cstdio>
using namespace std;

struct rectangle{
    int length;
    int breadth;
};
int main(){
    int A[] = {1,2,4,5,6};
    cout<<&A+1;
    struct rectangle r = {2,3};
    int a = r.length * r.breadth;
    cout<<a<<"\n";
    cout<<"Length of the Array is "<<(sizeof(A)/sizeof(A[0])); 
}