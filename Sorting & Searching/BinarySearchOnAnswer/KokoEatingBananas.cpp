#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    bool canFinish(int speed, int h, vector<int> &piles){
        long long takenHours = 0;
        for(int i = 0; i < piles.size(); i++){
            // Typecasting to double to avoid integer division and then taking ceil of the result to get the number of hours taken for each pile.
            takenHours += ceil((double)piles[i]/speed); 
        }

        if(takenHours <= h) return true;
        else return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        int minSpeed = 1;
        int maxSpeed = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while(minSpeed <= maxSpeed){
            int midSpeed = (minSpeed+maxSpeed)/2;

            if(canFinish(midSpeed, h, piles)){
                ans = midSpeed;
                maxSpeed = midSpeed-1;
            }else{
                minSpeed = midSpeed+1;
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
