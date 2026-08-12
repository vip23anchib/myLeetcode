// ============================================================
// 2095. DELETE THE MIDDLE NODE OF A LINKED LIST
// ============================================================
//
// Middle index = floor(n / 2)
//
// n = 1 → index 0
// n = 2 → index 1
// n = 3 → index 1
// n = 4 → index 2
// n = 5 → index 2
//
// ============================================================
// APPROACH 1: COUNT NODES → FIND MIDDLE INDEX → DELETE
// ============================================================
//
// Idea:
// 1. Count total number of nodes.
// 2. middle = n / 2
// 3. Traverse to the node BEFORE the middle.
// 4. Skip/delete the middle node.
//
// Example:
// 1 → 2 → 3 → 4 → 5
// n = 5
// middle = 5 / 2 = 2
// middle node = 3
//
// To delete 3, reach node 2:
//
// 1 → 2 → 3 → 4 → 5
//     prev  middle
//
// Then:
// prev->next = middle->next
//
// ============================================================

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // If only one node exists,
        // that node is the middle → return NULL.
        if (head->next == NULL)
            return NULL;

        // STEP 1: Count number of nodes
        int n = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            n++;
            temp = temp->next;
        }

        // STEP 2: Find middle index
        int middle = n / 2;

        // STEP 3: Go to the node BEFORE middle
        temp = head;

        for (int i = 0; i < middle - 1; i++) {
            temp = temp->next;
        }

        // STEP 4: Delete middle node
        ListNode* nodeToDelete = temp->next;

        // Skip the middle node
        temp->next = nodeToDelete->next;

        delete nodeToDelete;

        return head;
    }
};


// ============================================================
// APPROACH 2: SLOW + FAST POINTERS ⭐
// ============================================================
//
// Idea:
// slow → moves 1 node at a time
// fast → moves 2 nodes at a time
//
// Since fast moves twice as fast,
// when fast reaches the end,
// slow will be at the middle.
//
// BUT:
// To delete the middle, we also need the node BEFORE it.
//
// Therefore:
// prev → node before middle
// slow → middle
// fast → helps find middle
//
// Example:
//
// 1 → 2 → 3 → 4 → 5
//     ↑   ↑
//    prev slow
//
// Then:
// prev->next = slow->next
//
// Result:
//
// 1 → 2 → 4 → 5
//
// ============================================================

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // Special case:
        // If only one node exists, delete it.
        if (head->next == NULL)
            return NULL;

        // slow = finds the middle
        // fast = moves twice as fast as slow
        // prev = remembers node before slow
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        // We move fast by TWO nodes:
        // fast = fast->next->next
        //
        // Therefore BOTH must exist:
        // 1. fast != NULL
        // 2. fast->next != NULL
        //
        // Otherwise fast->next->next could access NULL.
        while (fast != NULL && fast->next != NULL) {

            // Save node BEFORE slow
            prev = slow;

            // Move slow by 1 step
            slow = slow->next;

            // Move fast by 2 steps
            fast = fast->next->next;
        }

        // At this point:
        // prev = node before middle
        // slow = middle node
        //
        // Skip the middle node
        prev->next = slow->next;

        // Delete the middle node
        delete slow;

        return head;
    }
};


// ============================================================
// QUICK MEMORY NOTES
// ============================================================
//
// APPROACH 1:
// COUNT → n/2 → reach previous → skip middle
//
// APPROACH 2 ⭐:
// slow = +1
// fast = +2
// prev = node before slow
//
// while:
//     prev = slow
//     slow = slow->next
//     fast = fast->next->next
//
// At the end:
//     slow = MIDDLE
//     prev = BEFORE MIDDLE
//
// Delete:
//     prev->next = slow->next;
//     delete slow;
//
// WHY fast->next CHECK?
// Because we do:
//     fast->next->next
//
// So fast AND fast->next must exist.
//
// WHY prev?
// Singly linked list cannot move backwards.
// To delete slow, we need the node before slow.
//
// TIME:  O(n)
// SPACE: O(1)
// ============================================================
