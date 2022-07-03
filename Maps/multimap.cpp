#include<iostream>
#include<map>
using namespace std;
int main(){
    //Insertion and Deletion takes Lograthmic Time
    multimap<int,string> m = { {10,"dog"},{20,"cat"}, {30,"tiger"}};
    
    pair<int,string> p = make_pair(10,"tipsy");
    m.insert(p);
   
    map<int,string> m2 = {{20,"daisy"}, {40,"lion"}};
    m.insert(m2.begin(),m2.end());

    for(auto i:m){
        cout<<i.first<<"-"<<i.second<<"  ";
    }

    cout<<endl;

    

    m.erase(20); //Deletes all occurences of key 20
    auto it = m.erase(m.find(20)); //Deletes One Occurenc of key 20


    for(auto i:m){
        cout<<i.first<<"-"<<i.second<<"  ";
    }

    return 0;
}