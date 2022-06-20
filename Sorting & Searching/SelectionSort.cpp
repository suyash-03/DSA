#include<iostream>
using namespace std;

void SelectionSort(int A[],int n){
    int iMin;
    int temp;
    for(int i=0; i<n-1; i++){ //We need to do n-1 passes
        iMin = i;
        for(int j=i+1; j<n; j++){  
            /* 
            In each pass that index element is assigned iMin and 
            array infront of it is checked for a smaller number
            if found, we use a temporary variable for swapping that number 
            out with the new one we have found
            */

            if(A[j] < A[iMin]){
                temp = A[iMin];
                A[iMin] = A[j];
                A[j] = temp;
            }
        }
    }

}

int main(){
    int A[] = {0,4,3,9,6,5,7};
    SelectionSort(A, 6);
    for(int i=0; i<6; i++){
        cout<<A[i]<<" ";
    }
    return 0;
}