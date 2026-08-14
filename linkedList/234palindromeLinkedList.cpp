// LC 234 — PALINDROME LINKED LIST
//
// Approach: Find middle → Reverse 2nd half → Compare
//
// 1. Find middle using slow & fast
//    slow moves 1 step, fast moves 2 steps.
//    When fast reaches the end, slow is around the middle.
//
// 2. Reverse the 2nd half starting from slow
//    Pattern: SAVE → REVERSE → MOVE → MOVE
//
//    nextNode = curr->next;  // SAVE next node before changing link
//    curr->next = prev;      // REVERSE arrow
//    prev = curr;            // MOVE prev
//    curr = nextNode;        // MOVE curr
//
//    After reversal, `prev` = head of reversed 2nd half.
//
// 3. Compare first half and reversed 2nd half
//    first = head
//    second = prev
//
//    If first->val != second->val → false
//    If all match → true
//
// Why reverse?
// Singly LL cannot move backwards.
// Reversing the 2nd half lets us compare both halves left → right.
//
// Example:
// 1 → 2 → 3 → 2 → 1
//          ↓
// 1 → 2 → 3    and    1 → 2
// Compare: 1=1, 2=2 → palindrome.
//
// Time: O(n)
// Space: O(1)


class Solution {
public:
    bool isPalindrome(ListNode* head) {

        // STEP 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }


        // STEP 2: Reverse the second half
        ListNode* prev = NULL;
        ListNode* curr = slow;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        // prev is now the head of the reversed second half


        // STEP 3: Compare first half and reversed second half
        ListNode* first = head;
        ListNode* second = prev;

        while (second != NULL) {

            if (first->val != second->val) {
                return false;
            }

            first = first->next;
            second = second->next;
        }


        // STEP 4: Everything matched
        return true;
    }
};
