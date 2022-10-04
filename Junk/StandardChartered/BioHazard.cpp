#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> subarrays;
void generateSubArrays(vector<int> arr, int start, int end){ 
    vector<int> subarray;    
    if (end == arr.size())  return;             
    else if (start > end)         
    generateSubArrays(arr, 0, end + 1);                 
    else{         
        for (int i = start; i < end; i++){
            subarray.push_back(arr[i]);         
        } 
        subarray.push_back(arr[end]);  
        subarrays.push_back(subarray);      
        generateSubArrays(arr, start + 1, end);     
    }        
    return;
    } 
    int bioHazard(int n,  vector<int> allergic, vector<int> poisonous){     
        int ans = 0;     
        generateSubArrays(allergic, 0, 0);     
        for(int i = 0; i < subarrays.size(); ++i){         
            int c = 0;         
            for(int j = 0; j < poisonous.size(); ++j){
                auto it = find(subarrays[i].begin(), subarrays[i].end(), poisonous[j]); 
                if(it == subarrays[i].end()){     
                    ++c;           
                }         
        }        
        if(c == 0 || c == subarrays[i].size()){          
            ++ans;       
    }  
         }   
         return ans; }  
    int main() {   
            vector<int> allergic = {1,2};    
            vector<int> poisonous = {3, 4}; 
            cout << bioHazard(2, allergic, poisonous);  
            return 0;
    }
 

 