#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Your code goes here
        unordered_map<char, int> freq;
        for(auto t: tasks){
            freq[t]++;
        }

        priority_queue<int> pq;
        queue<pair<int,int>> waitingQueue;

        for(auto it: freq){
            pq.push(it.second);
        }
        int time = 0;
        while(!pq.empty() || !waitingQueue.empty()){
            time++;
            if(!pq.empty()){
                int topFreq = pq.top();
                pq.pop();
                topFreq--;

                if(topFreq > 0){
                    waitingQueue.push({topFreq, time+n});
                }
            }

            if(!waitingQueue.empty() && waitingQueue.front().second == time){
                pq.push(waitingQueue.front().first);
                waitingQueue.pop();
            }
        }
        return time;
    }
    
};

int main() {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;

    Solution solution;
    cout << solution.leastInterval(tasks, n) << endl;

    return 0;
}
