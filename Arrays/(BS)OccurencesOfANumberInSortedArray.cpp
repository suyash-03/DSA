#include<iostream>
using namespace std;
//Binary Search will be Used to find first and last occurence of the number in a sorted array

int findFirstOccurence(int A[],int n,int x){
    int result = -1;
    int start = 0;
    int end = n-1;
    while(start <= end){
        int middle = (start+end)/2;
        if(A[middle] == x){
            result = middle;
            end = middle-1;
        }else if(x < A[middle] ){
            end = middle-1;
        }else{
            start = middle+1;
        }
    }
   return result;
}

int findLastOccurence(int A[], int n,int x){
    int start = 0;
    int end = n-1;
    int result = -1;
    while(start <= end){
        int middle = (start+end)/2;
        if(A[middle] == x){
            result = middle;
            start = middle + 1;
        }else if(x < A[middle]){
            end = middle-1;
        }else{
            start = middle+1;
        }
    }
    return result;
    
}

int occurenceOfANumber(int A[],int n,int x){
    int firstOccurence = findFirstOccurence(A,n,x);
    int lastOccurence = findLastOccurence(A,n,x);
    return (lastOccurence - firstOccurence + 1);
}


int main(){
    int A[] = {1,2,3,4,4,4,6,7,9,};
    int result = occurenceOfANumber(A,9,4);
    cout<<result;
    return 0;
}