#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(int target) {
        target = abs(target);
        int step = 0;
        int res = 0;
        
        while(res < target || (res - target)%2 != 0)
        {
            step++;
            res += step;
        }
        
        return step;
}
