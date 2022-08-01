#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int pivotIndexBetter(vector<int> nums){
    int rightSum = accumulate(nums.begin(),nums.end(),0);
        int leftSum = 0;
        for(int i=0;i<nums.size();i++){            
            rightSum -= nums[i];
            if(leftSum == rightSum){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
}

int pivotIndex(vector<int>& nums) {
    int index = 0;
    int sumR = 0;
    int sumL = 0;
    while(index < nums.size()){
        sumR = 0;
        sumL =0;
        if(index == 0){
            sumR = 0;
        }else{
            for(int i=0;i<index;i++){
                sumR = sumR + nums[i];
            }
        }
        if(index == nums.size()-1){
            sumL = 0;
        }else{
            for(int j=index+1;j<nums.size(); j++){
                sumL = sumL + nums[j];
                }
        }
        cout<<"For Index: "<<index<<"  Left Sum:  "<<sumL<<"  Right Sum:  "<<sumR<<endl; 
         if(sumR == sumL){
            return index;
        }
        index = index + 1;
    }
        return -1;
    }
    
int main(){
    vector<int> v1;
    v1.push_back(-1); v1.push_back(-1);
    v1.push_back(1); v1.push_back(1);
    v1.push_back(0); v1.push_back(0);
    int result = pivotIndex(v1);
    cout<<result<<endl;
    return 0;
}