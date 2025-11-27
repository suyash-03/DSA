class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // 1. Find the middle of the list (slow pointer will be at the end of the first half)
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 2. Separate the list and mark the start of the second half
        ListNode* headB = slow->next; // 4 for [1,2,3,4,5], 3 for [1,2,3,4]
        slow->next = NULL;           // End of first half: 3->NULL for [1,2,3,4,5]
        ListNode* headA = head;

        // 3. Reverse the second half (headB)
        ListNode* prev = NULL;
        ListNode* current = headB;
        while (current) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        headB = prev; // headB is now the new head of the reversed list (e.g., 5 for [4,5])

        // 4. Merge the two halves
        while (headB) {
            ListNode* nextA = headA->next;
            ListNode* nextB = headB->next;

            headA->next = headB; // Link A to B
            headB->next = nextA; // Link B to A's next

            headA = nextA;
            headB = nextB;
        }
    }
};