// ============================================================
// 2. ADD TWO NUMBERS
// Approach: Traverse both linked lists + carry
// ============================================================
//
// IMPORTANT:
// Lists store digits in REVERSE order.
// 2 → 4 → 3 represents 342.
//
// At every step:
//     sum = digit1 + digit2 + carry
//     digit = sum % 10       → digit to store
//     carry = sum / 10       → carry to next position
//
// DIFFERENT LENGTHS:
// If one list is finished, treat its digit as 0.
//     l1 != NULL ? l1->val : 0
//     l2 != NULL ? l2->val : 0
//
// LOOP CONDITION:
//     while (l1 != NULL || l2 != NULL || carry != 0)
//
// Continue if:
//     • l1 still has nodes
//     • OR l2 still has nodes
//     • OR a final carry is left
//
// DUMMY NODE:
// Used to easily build the result list.
// Answer starts from dummy->next.
//
// TIME:  O(max(m,n))
// SPACE: O(max(m,n))  → result list
// ============================================================

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node simplifies result-list creation
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        int carry = 0;

        // Continue while either list has nodes OR carry remains
        while (l1 != NULL || l2 != NULL || carry != 0) {

            // If a list is finished, use 0
            int x = (l1 != NULL) ? l1->val : 0;
            int y = (l2 != NULL) ? l2->val : 0;

            // Add both digits + previous carry
            int sum = x + y + carry;

            // Current digit
            int digit = sum % 10;

            // Carry for next position
            carry = sum / 10;

            // Add digit to result list
            current->next = new ListNode(digit);
            current = current->next;

            // Move pointers if nodes still exist
            if (l1 != NULL)
                l1 = l1->next;

            if (l2 != NULL)
                l2 = l2->next;
        }

        // Dummy itself is not part of answer
        return dummy->next;
    }
};
