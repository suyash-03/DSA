#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int res;
void printTheArray(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++) {
        if(i == 0) continue;
        else if(arr[i] == 1 && arr[i-1] == 1){
            cout<<res<<" ";
            res--;
            break;
        }
    }
}
 
// Function to generate all binary strings
void generateAllBinaryStrings(int n, vector<int> &arr, int i)
{
    if (i == n) {
        printTheArray(arr, n);
        return;
    }
    arr[i] = 0;
    generateAllBinaryStrings(n, arr, i + 1);
    arr[i] = 1;
    generateAllBinaryStrings(n, arr, i + 1);
}


int main() {
    int n;
    cin>>n;
    long long int numStrings = pow(2,n);
    vector<int> arr(numStrings);
    res = numStrings;
    cout<<res<<endl;
    generateAllBinaryStrings(n, arr, 0);
    cout<<res%(1000000007);
    return 0;
}