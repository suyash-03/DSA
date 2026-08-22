#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    bool canLoad(int capacity, int days, vector<int>& weights) {
        int currentWeight = 0;
        int currentDays = 1;

        for(int weight : weights) {
            if(currentWeight + weight > capacity) {
                currentDays++;
                currentWeight = 0;
            }

            currentWeight += weight;
        }

        return currentDays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans = 0;
        // If we load all items in single day
        int maxCapacity = accumulate(weights.begin(), weights.end(), 0);
        // Anything lower wouldn't allow us to keep the items
        int minCapacity = *max_element(weights.begin(), weights.end());

        while(minCapacity <= maxCapacity){
            int midCapacity = (minCapacity + maxCapacity)/2;

            if(canLoad(midCapacity, days, weights)){
                ans = midCapacity;
                maxCapacity = midCapacity-1;
            }else{
                minCapacity = midCapacity+1;
            }
        }

        return ans;
    }
};
