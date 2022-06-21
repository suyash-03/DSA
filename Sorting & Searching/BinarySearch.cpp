#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int BinarySearch(vector<int> A, int n, int x){
    int start = 0;
    int end = n-1;
    while(start <= end){
        int middle = (start+end)/2;
        if(A[middle] == x){
            return middle;
        }else if(x < A[middle]){
            end = middle-1;
        }else{
            start = middle+1;
        }
    }
    return -1;
}

int BinarySearchRecursive(vector<int> A,int low,int high,int x){
    if(low > high){
        return -1;
    }
    int middle = (low + high)/2;
    if(x == A[middle]){
        return middle;
    }else if(x < A[middle]){
        return BinarySearchRecursive(A,low,middle-1,x);
    }else{
        return BinarySearchRecursive(A,middle+1,high,x);
    }
}

int main(){
    vector<int> A;
    A.push_back(5);A.push_back(3);
    A.push_back(2);A.push_back(9);
    A.push_back(1);A.push_back(8);
    A.push_back(0);
    sort(A.begin(),A.end());
    // Binary Search works on Sorted Arrays and has time complexity 0(log n)
    int resultRecursive = BinarySearchRecursive(A,0,6,2);
    int result = BinarySearch(A,7,2);
    cout<<"Result Index: "<<resultRecursive<<endl;
    cout<<"Result Index: "<<result;
    return 0;
}