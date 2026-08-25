#include <iostream>
#include <unordered_map>
#include <mutex>
using namespace std;

class Node{
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(){
        key = -1;
        value = -1;
        prev = next = NULL;
    }    

    Node(int key, int value){
        this->key = key;
        this->value = value;
        prev = next = NULL;
    }
};

class LRUCache {
public:
    mutex mtx;

    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node){
        Node* nextNode = head->next;
        head->next = node;
        nextNode->prev = node;
        node->prev = head;
        node->next = nextNode;
    }

    unordered_map<int, Node*> myMap;
    int capacity;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        lock_guard<mutex> lock(mtx);

        if(myMap.find(key) == myMap.end()){
            return -1;
        }

        Node* node = myMap[key];
        int val = node->value;

        deleteNode(node);
        insertAfterHead(node);

        return val;
    }

    void put(int key, int value) {
        lock_guard<mutex> lock(mtx);

        if(myMap.find(key) != myMap.end()){
            Node* node = myMap[key];
            node->value = value;

            deleteNode(node);
            insertAfterHead(node);
            return;
        }

        if(myMap.size() == capacity){
            Node* lru = tail->prev;

            myMap.erase(lru->key);
            deleteNode(lru);
            delete(lru);
        }

        Node* newNode = new Node(key, value);
        myMap[key] = newNode;
        insertAfterHead(newNode);
    }
};

int main(){
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;

    cache.put(3, 3);
    cout << cache.get(2) << endl;

    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    return 0;
}


