// 19. Remove Nth Node From End of List

// Given the head of a linked list, remove the nth node from the end of the list and return its head.
// Example 1:

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

//------------------------------------------------------------------------------------------------------
//APPROACH 1:

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head;
        int size=0;

        while(temp!=NULL){
            size++;
            temp=temp->next;
        }

        int required= size-n;
        temp=head;

        if (n == size) {
            ListNode* deleteNode = head;
            head = head->next;
            delete deleteNode;
            return head;
        }

        for(int i=1;i<required;i++){
            temp=temp->next;
        }

        ListNode* deleteNode=temp->next;

        temp->next=temp->next->next;

        delete deleteNode;

        return head;
    }
};


//APPROACH 2 
//USING SLOW AND FAST POINTER 

// ============================================================
// 19. REMOVE NTH NODE FROM END OF LIST
// Approach: Fast + Slow Pointers
// ============================================================
//
// IDEA:
// Create a gap of N nodes between fast and slow.
// When fast reaches the LAST node,
// slow will be at the node BEFORE the one to delete.
//
// Example: 1 → 2 → 3 → 4 → 5, n = 2
//
// After moving fast N steps:
// slow → 1
// fast → 3
//
// Move both until fast reaches LAST node:
// 1 → 2 → 3 → 4 → 5
//         slow     fast
//
// slow is now at 3, and slow->next (4) is the node to delete.
//
// WHY fast->next != NULL and NOT fast != NULL?
// ------------------------------------------------------------
// We want slow to STOP at the node BEFORE the target.
//
// If we use:
//     while (fast != NULL)
// fast moves one step too far → slow also moves too far.
//
// So we use:
//     while (fast->next != NULL)
// This stops when fast is at the LAST node.
// Therefore, slow is exactly BEFORE the node to delete.
//
// SPECIAL CASE:
// If fast == NULL after moving N steps,
// it means the HEAD itself is the node to delete.
//
// Example: 1 → 2 → 3, n = 3
// fast moves 3 steps → NULL
// So return head->next.
//
// TIME:  O(n)
// SPACE: O(1)
// ============================================================

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Start both pointers at head
        ListNode* slow = head;
        ListNode* fast = head;

        // Create a gap of n nodes
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast reaches NULL,
        // head itself is the Nth node from the end
        if (fast == NULL) {
            return head->next;
        }

        // Move together until fast is at the LAST node
        // This keeps slow at the node BEFORE the target
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Skip/delete the target node
        slow->next = slow->next->next;

        return head;
    }
};
