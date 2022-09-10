#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class  Solution{
    public:
    string solution(string s){
        map<char,int> fq;
        for(int i=0; i<s.size(); i++){
            fq[s[i]]++;
        }

        string res = "";
        for(auto it:fq){
            if(it.second >= 2 ){
                while(fq[it.first] >= 2){
                    res = it.first + res + it.first;
                    fq[it.first] = fq[it.first] - 2;
                }
            }
        }
        if(!res.empty()) res = to_string(stoi(res));
        
        int maxi = INT_MIN;
        for(auto it:fq){
            if(it.second > 0){
                int num = it.first-48;
                maxi = max(num,maxi);
            }
        }
        string ans = "";

        if(maxi == INT_MIN){
            ans = res;
        }else{
            int n = res.size();
            if(n > 1){
                string firstPart = res.substr(0,n/2);
                string secondPart = res.substr(n/2,n);
                ans = firstPart + to_string(maxi) + secondPart;
            }else{
                ans = to_string(maxi);
            }
        }   
        
        return ans;
    }
};

int main(){
    Solution s;
    // 55143000
    string ans  = s.solution("55143000");
    cout<<ans<<endl;
    return 0;
}