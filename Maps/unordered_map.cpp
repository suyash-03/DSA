#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    unordered_map<string,int> myMap;
    
    //Method 1 to Insert
    pair<string,int> p("Suyash",100);
    myMap.insert(p);

    //Method 2 to Insert
    myMap["Shreyas"] = 99;
    myMap["Rohit"] = 57;
    myMap["Kishlay"] = 78;
    myMap["Aditya"] = 65;

    //Method 1 to Print
    cout<<myMap["Suyash"]<<endl;

    //Method 2 to Print
    cout<<myMap.at("Shreyas")<<endl;

    /* If a key does not exist and we access it
       via this method default value 0 gets printed
       However cout<<myMap.at("Arthur"); will throw an error  */
    
    cout<<myMap["Arthur"]<<endl;
    cout<<myMap.size()<<endl;

    unordered_map<string,int>::iterator itr = myMap.begin();
    cout<<itr->first<<endl;
    
    for (auto i = myMap.begin(); i != myMap.end(); i++) {
        std::cout << i->first<< " : "<< i->second << '\n';
    }
    cout<<endl;
    
    for(auto i:myMap){
        cout<<i.first<<" "<<i.second;
        cout<<endl;
    }

    //To check presence of a key

     if(myMap.find("Suyash") != myMap.end()){
        cout<<"The value with key Suyash Exists \n";
    }

    if(myMap.count("John") == 0){
        cout<<"Key John doest not exist";
    }
}