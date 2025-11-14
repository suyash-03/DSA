#include <vector>
#include <utility>

class Solution{
    public:
    // Sort By Meeting End time
    // We will greedily take the meetings that are ending first;
    static bool cmp(pair<int,int> &a, pair<int,int> &b){
        return a.second < b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end){
        //your code goes here
        vector<pair<int,int>> meetings;
        for(int i = 0; i < start.size(); i++){
            meetings.push_back({start[i], end[i]});
        }

        sort(meetings.begin(), meetings.end(), cmp);
        int n = meetings.size();
        int ans = 1;
        pair<int,int> lastMeet = meetings[0];
        for(int i = 1; i < n; i++){
            if(meetings[i].first > lastMeet.second){
                ans++;
                lastMeet = meetings[i];
            }
        }

        return ans;
    }
};