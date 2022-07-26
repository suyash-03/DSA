#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int countingnodes=0;
class Node
{
    public:
    map<char,Node*>children;
    char ch;
    bool terminal;
    Node(char data)
    {
        ch=data;
        terminal=false;
    }
};
class Trie
{
    public:
    Node*root;
    // int count;
    Trie()
    {
        root=new Node('\0');
        
    }
    void insert(string a)
    {
        Node*temp=root;
        for(int i=0;i<a.size();i++)
        {
            if(temp->children.find(a[i])==temp->children.end())
            {
                temp->children[a[i]]=new Node(a[i]);
                countingnodes++;
            }
            temp=temp->children[a[i]];
        }
        temp->terminal=true;
    }
};
int main()
{
    vector<string>s;
    for(int i=0;i<4;i++)
    {
        map<char,int>mp;
        string temp;
        cin>>temp;
        s.push_back(temp);
        for(int i=0;i<temp.size();i++)
        {
            mp[temp[i]]++;
        }
        temp="";
        for(int z=0;z<26;z++)
        {
            char ch='a'+z;
            while(mp[ch])
            {
                temp=temp+ch;
                mp[ch]--;
                
            }
        }
        s[i]=temp;
        // cout<<temp<<endl;
    }
    Trie t;
    for(int i=0;i<4;i++)
    {
        t.insert(s[i]);
    }
    cout<<countingnodes;
    
}