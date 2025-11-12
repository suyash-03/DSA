/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> st;
        while(headA != NULL){
            st.insert(headA);
            headA = headA->next;
        }

        ListNode *ans;
        while(headB != NULL){
            if(st.find(headB) != st.end()){
                ans = headB;
                break;
            }
            headB = headB->next;
            
        }

        return ans;
    }
};