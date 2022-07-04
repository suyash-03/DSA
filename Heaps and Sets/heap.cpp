#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;
        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }else{
                return;
            }
        }
    }

    void print(){
        for(int i = 1; i<=size; i++){
            cout<<arr[i]<<" ";
        }
    }

    //Deleting from a heap always means removing the top most node of the heap
    void deleteFromHeap(){
        if(size == 0){
            cout<<"Nothing to Delete"<<endl;
        }
        //step 1: swap first node to last node
        arr[1] = arr[size];

        //step 2: remove the last element
        size--;

        //step 3: take root node to it's correct position
        int i = 1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;
            if(arr[i] < arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }else if(arr[i] < arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }else{
                return;
            }
        }
    }
};

int main(){
    heap h;
    h.insert(5);
    h.insert(6);
    h.insert(1);
    h.insert(9);
    h.print();
    h.deleteFromHeap();
    cout<<endl;
    h.print();
    return 0;
}