#include<iostream>
#include<map>
#include<string>
 
using namespace std;
 
int main(){
 
    // Map is an associative array
    map<string, int>  marksMap;
    marksMap["Atul"] = 58;
    marksMap["Rohit"] = 57;
    marksMap["Kishlay"] = 78;
    marksMap["Aditya"] = 65;
    marksMap["Sachin"] = 53;
    
    marksMap.insert( 
        { 
        {"Rohan", 89}, 
        {"Akshat", 46}
        } 
    );

    cout<<marksMap["Atul"]<<endl;

    //Inserts default value 0 to a key if while accessing a key that does not exist
    cout<<marksMap["Suyash"]<<endl;

    map<string,int>::iterator ptr = marksMap.begin();
    

    //Accessing elements in sorted order
    map<string,int> :: iterator iter;
    for (iter = marksMap.begin(); iter != marksMap.end(); iter++)
    {
        cout<<iter->first<<" "<<(*iter).second<<"\n";
    }
    
 
    return 0;
}
