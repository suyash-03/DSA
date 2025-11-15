#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int min_price = prices[0];
        int max_profit = 0;
        for (int p : prices) {
            if (p < min_price) min_price = p;
            else max_profit = max(max_profit, p - min_price);
        }
        return max_profit;
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
