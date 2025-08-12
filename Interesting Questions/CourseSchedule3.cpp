#include <vector>
#include <queue>            
#include <utility>
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static bool compareByLastDay(const vector<int> &a,const vector<int> &b){
        return a[1] < b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), compareByLastDay);
        priority_queue<int> maxCourseDuration;

        int numCourses = 0;
        int currentTime = 0;
        
        for(auto it: courses){
            currentTime += it[0];
            maxCourseDuration.push(it[0]);
            if(currentTime > it[1]){
                currentTime -= maxCourseDuration.top();
                maxCourseDuration.pop();
            }else{
                numCourses++;
            }
        }

        return numCourses;
    }
};

int main() {
    Solution s;
    vector<vector<int>> courses = {{100,200}, {200,1300}, {300, 1400}, {400, 1500}};
    int result = s.scheduleCourse(courses);
    cout << "Maximum number of courses that can be taken: " << result << endl;
    return 0;
}
// Example Input: courses = [[100,200],[200,1300],[300,1400],[400,1500]]
// Example Output: 3
// Explanation: The maximum number of courses that can be taken is 3, which can be achieved by taking the first, second, and fourth courses.
// The third course cannot be taken because it would exceed the last day of the second course.  