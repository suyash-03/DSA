#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxDiff(int arr[], int n)
{
    int result = 0;
 
    // sort the array
    sort(arr, arr + n);
 
    // calculate the result
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1])
            result += abs(arr[i]);
        else
            i++;
    }
 
    // check for last element
    if (arr[n - 2] != arr[n - 1])
        result += abs(arr[n - 1]);
 
    // return result
    return result;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res = maxDiff(arr,n);
    cout<<res<<endl;

}