#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        for(int i = 0; i < k; i++){
            if(temp == NULL){
                return head;
            }
            temp = temp->next;
        }

        ListNode *current = head;
        ListNode *prev = NULL;
        ListNode *nextLocal = NULL;

        for(int i = 0; i < k; i++){
            nextLocal = current->next;
            current->next = prev;
            prev = current;
            current = nextLocal;
        }
        
        head->next = reverseKGroup(current, k);
        return prev;
    }
};