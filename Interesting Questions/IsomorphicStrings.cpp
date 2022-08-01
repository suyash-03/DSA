#include<iostream>
#include<unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {
        unordered_map<char,int> uniqueS;
        unordered_map<char,int> uniqueT;
        if(s.length() != t.length()){
            cout<<"Unequal Length"<<endl;
            return false;
        }else{
            for(int i=0; i<s.length(); i++){
                if(uniqueS.count(s[i]) == 0){
                    cout<<s[i]<<endl;
                    uniqueS[s[i]] = i;
                }
            }
            cout<<endl;
            cout<<endl;
            for(int j=0; j<t.length(); j++){
                if(uniqueT.count(t[j]) == 0){
                    cout<<t[j]<<endl;
                    uniqueT[t[j]] = j;
                }
            }
            if(uniqueS.size() == uniqueT.size()){
                return true;
            }else{
                return false;
            }
        }
}
int main(){
    string s = "foo";
    string t = "bar";
    bool result = isIsomorphic(s,t);
    cout<<result<<endl;
    return 0;
}