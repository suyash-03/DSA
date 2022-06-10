#include<iostream>
using namespace std;

void BubbleSort(int A[],int n){
    /*In Bubble Sort We compare the Ith element to it's next
    element in the array. If it's bigger than it's next element we 
    swap it. This loop in the worst case is run (n-1) times
    */
    for(int j=0 ; j<n-1; j++){
        int temp;
        int flag = 0;   //flag used to check if it has been sorted before the n-1 passes
        for(int i=0 ; i<n-j-1; i++){
            if(A[i]>A[i+1]){
                temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}

int main(){
    int A[] = {1,5,3,8,9,6};
    BubbleSort(A,6);
    for(int i=0 ; i<6 ; i++){
        cout<<A[i]<<" ";
    }
    return 0;
}