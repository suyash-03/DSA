/*
A priority queue is a container adaptor that provides constant time lookup of the largest (by default) element,
 at the expense of logarithmic insertion and extraction.
*/
#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pq;
    priority_queue<int ,vector<int>, greater<int>> pqMin;
    pq.push(5); pqMin.push(5);
    pq.push(7); pqMin.push(7);
    pq.push(1); pqMin.push(1);
    pq.push(8); pqMin.push(8);
    cout<<pq.top()<<endl;
    cout<<pqMin.top()<<endl;
    return 0;
}