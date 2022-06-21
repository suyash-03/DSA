/* Binary Search works on Sorted Arrays and has time complexity 0(log n)
   if sorted array has more than one occurence of a number
   we can either return the first occurence of a number or the last occurence of a number */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int BinarySearchFirstOccurence(vector<int> A, int n, int x){
    int start = 0;
    int end = n-1;
    int result = -1;
    while(start <= end){
        int middle = (start+end)/2;
        if(A[middle] == x){
            result = middle;
            end = middle - 1;
        }else if(x < A[middle]){
            end = middle-1;
        }else{
            start = middle+1;
        }
    }
    return result;
}
int BinarySearchLastOccurence(vector<int> A, int n, int x){
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


int main(){
    vector<int> A;
    A.push_back(5);A.push_back(3);
    A.push_back(2);A.push_back(9);
    A.push_back(1);A.push_back(8);
    A.push_back(0);A.push_back(2);
    A.push_back(2);A.push_back(12);
    sort(A.begin(),A.end());
    
    int resultFO = BinarySearchFirstOccurence(A,10,2);
    int resultLO = BinarySearchLastOccurence(A,10,2);
    cout<<"Result Index: "<<resultFO<<endl;
    cout<<"Result Index: "<<resultLO;
    return 0;
}