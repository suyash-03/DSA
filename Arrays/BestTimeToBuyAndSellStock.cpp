#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read n followed by n prices from stdin:
    // Example input:
    // 6
    // 7 1 5 3 6 4
    int n;
    if (!(cin >> n)) return 0;
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) cin >> prices[i];

    Solution sol;
    cout << sol.maxProfit(prices) << '\n';
    return 0;
}
