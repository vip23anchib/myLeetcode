// 237. Delete Node in a Linked List
//
// We are given ONLY the node to delete.
// We DON'T have head or previous node.
//
// Normally:
// prev -> node -> next
// prev->next = node->next;
//
// But here, prev is unavailable.
//
// TRICK:
// Make current node become the next node,
// then skip the next node.
//
// Example:
// 4 -> [5] -> 1 -> 9
//       node
//
// 1. Copy next value:
//    node->val = node->next->val;
//
//    4 -> [1] -> 1 -> 9
//
// 2. Skip next node:
//    node->next = node->next->next;
//
//    4 -> 1 -> 9
//
// IMPORTANT:
// node is guaranteed NOT to be the last node,
// because we need node->next.

class Solution {
public:
    void deleteNode(ListNode* node) {

        // Copy next node's value into current node
        node->val = node->next->val;

        // Skip the next node
        node->next = node->next->next;
    }
};
