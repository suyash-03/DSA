//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	vector<int> dp{vector<int>(1000002,-1)};
	int findMaxSum(int *arr, int n) {
	    if(n <= 0){
	        return dp[n] = 0;
	    }
	    if(dp[n] != -1){
	        return dp[n];
	    }
	    return dp[n] = max(arr[n-1] + findMaxSum(arr,n-2),findMaxSum(arr,n-1));
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends