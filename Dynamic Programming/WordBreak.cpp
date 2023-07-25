class Solution {
public:
    unordered_map<string,int> dictionary;
    bool wordBreakUtil(string s,int pos,vector<int> &dp){
        if(pos == s.size()){
            return true;
        }
        if(dp[pos] != -1){
            return dp[pos];
        }
        for(int i = pos; i < s.size(); i++){
            //Start Checking all possible susbtrings for occurence
            string t = s.substr(pos,i-pos+1);
            if(dictionary.find(t) != dictionary.end() && wordBreakUtil(s,i+1,dp)){
                return dp[pos] = true;
            }
        }
        return dp[pos] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto it: wordDict){
            dictionary[it]++;
        }
        int n = s.size();
        vector<int> dp(n+1,-1);
        return wordBreakUtil(s,0,dp);

    }
};
