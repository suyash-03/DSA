#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compareBySecond(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int minTimeToDefuseAll(int n, vector<pair<int,int>> &bombInfo) {
    // Sort by deadline (Yi)
    sort(bombInfo.begin(), bombInfo.end(), compareBySecond);
    // bombInfo now contains pairs of (Xi, Yi) sorted by Yi
    // where Xi is the time to defuse and Yi is the deadline

    long long currentTime = 0;
    for (auto &bomb : bombInfo) {
        currentTime += bomb.first; // add time to defuse
        if (currentTime > bomb.second) {
            return -1; // missed deadline
        }
    }
    return (int)currentTime;
}

int main() {
    int n = 5;
    vector<pair<int,int>> bombInfo = {
        {2,4}, {1,9}, {1,8}, {4,9}, {3,12}
    };
    cout << minTimeToDefuseAll(n, bombInfo) << endl; // Expected 11
    return 0;
}
