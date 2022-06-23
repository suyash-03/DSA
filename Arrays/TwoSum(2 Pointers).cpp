#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> twoSum(vector<int> a,int target){
    vector<int> result;
        //Two Pointer Technique
        int i = 0;
        int j = a.size() - 1;
        while(i<j){
            if(a[i] + a[j] == target){
                result.push_back(i);
                result.push_back(j);
                break;
            }else if(a[i] + a[j] < target){
                i++;
            }else if(a[i] + a[j] > target){
                j--;
            }
        }
        return result;
}

int main(){
    vector<int> a;
    a.push_back(3);  a.push_back(4);
    a.push_back(5); 
    vector<int> result = twoSum(a,7);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}