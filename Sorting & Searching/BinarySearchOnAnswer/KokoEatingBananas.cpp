#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    long long calculateMinHours(int speed, vector<int> &piles){
        long long hours = 0;
        for(int i = 0; i < piles.size(); i++){
            hours += ceil((double)piles[i] / speed); 
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int min_speed = 1;
        int max_speed = *max_element(piles.begin(), piles.end());

        int start = min_speed;
        int end = max_speed;
        int ans = -1;

        while(start <= end){
            int middle = start + (end - start) / 2;
            if(calculateMinHours(middle, piles) <= h){
                ans = middle;
                end = middle-1;
            }else{
                start = middle + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    int result = sol.minEatingSpeed(piles, h);
    return 0;
}
