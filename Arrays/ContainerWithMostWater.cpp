#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;

        int maxArea = 0;
        while (i < j) {
            int area = min(height[i], height[j]) * (j - i);
            maxArea = max(area, maxArea);

            // Move the shorter line because it is the only side that can
            // increase the possible area after width shrinks.
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxArea;
    }
};
