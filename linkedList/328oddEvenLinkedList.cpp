// ODD EVEN LINKED LIST — LC 328
//
// Goal:
// Group nodes at odd indices first,
// followed by nodes at even indices.
//
// Example:
// 1 → 2 → 3 → 4 → 5
//
// becomes:
//
// 1 → 3 → 5 → 2 → 4
//
// IMPORTANT:
// Odd/even refers to INDEX, NOT node value.
//
// Approach:
// Maintain 2 lists:
//
// odd:   1 → 3 → 5
// even:  2 → 4
//
// Then connect:
// odd → even
//
// Pointers:
//
// odd      = head
// even     = head->next
// evenHead = even
//
// evenHead is saved because `even` keeps moving.
// We need the original beginning of the even list
// at the end.
//
// Core logic:
//
// while (even != NULL && even->next != NULL) {
//
//     odd->next = even->next;
//     odd = odd->next;
//
//     even->next = odd->next;
//     even = even->next;
// }
//
// odd->next = evenHead;
//
// Time: O(n)
// Space: O(1)

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        // If there are 0 or 1 nodes,
        // nothing needs to be changed
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // First odd node
        ListNode* odd = head;

        // First even node
        ListNode* even = head->next;

        // Save the beginning of even list
        ListNode* evenHead = even;

        // Build odd and even lists
        while (even != NULL && even->next != NULL) {

            // Connect current odd node
            // to the next odd node
            odd->next = even->next;

            // Move odd pointer forward
            odd = odd->next;

            // Connect current even node
            // to the next even node
            even->next = odd->next;

            // Move even pointer forward
            even = even->next;
        }

        // Attach even list after odd list
        odd->next = evenHead;

        return head;
    }
};

