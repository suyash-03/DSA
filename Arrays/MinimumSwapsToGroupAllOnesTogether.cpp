//{ Driver Code Starts
// C++ program to find minimum swaps
// required to group all 1's together
#include <bits/stdc++.h>

using namespace std;

// Function to find minimum swaps
// to group all 1's together
int minSwaps(int arr[], int n) ;


// Driver Code
int main() {
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << minSwaps(a, n)<<endl;
    
    }

    return 0;
}

// } Driver Code Ends


int minSwaps(int arr[], int n) {
    //Sliding Window
    
    int oneCount = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 1){
            oneCount++;
        }
    }
    if(oneCount == 0) return -1;
    //One Count is the size of Sliding Window
    //Now we need to find minimum zeros in each sliding window
    
    int res = n-oneCount;
    int start = 0;
    int end = oneCount-1;
    int r = 0;
    for(int i=0; i<= end; i++){
        if(arr[i] == 0){
            r++;
        }
    }
    
    while(end < n){
        res = min(res,r);
        start++;
        end++;
        if(arr[end] == 0){
            r++;
        }
        if(arr[start-1] == 0){
            r--;
        }
    }
    
    return res;
    
}