#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;    

vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> st;
    for(int i=0; i<nums.size(); i++){
        unordered_map<int,int> myMap;
        for(int j=i+1; j<nums.size(); j++){
            int toFind = -(nums[i] + nums[j]);
            if(myMap.find(toFind) != myMap.end()){
                vector<int> temp = {nums[i], nums[j], toFind};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            myMap[nums[j]]++;
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

vector<vector<int>> threeSumOptimal(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for(int i=0; i<nums.size(); i++){
        if(i > 0 && nums[i] == nums[i-1]) continue; // Skip duplicates
        int left = i + 1;
        int right = nums.size() - 1;
        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];       
            if(sum < 0){
                left++;
            } else if(sum > 0){
                right--;
            } else {
                ans.push_back({nums[i], nums[left], nums[right]});
                while(left < right && nums[left] == nums[left + 1]) left++; // Skip duplicates
                while(left < right && nums[right] == nums[right - 1]) right--; // Skip duplicates
                left++;
                right--;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSumOptimal(nums);
    cout << "Three Sum Results:" << endl;
    for(const auto& triplet : result){
        cout << "[";
        for(int i = 0; i < triplet.size(); i++){
            cout << triplet[i];
            if(i < triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}