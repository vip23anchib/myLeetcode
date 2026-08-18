// APPROACH 1 : BRUTE FORCE
// USING LOOPS

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n=nums1.size();
        int m=nums2.size();

        vector<int>ans;

        for(int i=0;i<n;i++){
            bool found=false;
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    int ind=j+1;
                    while(ind<m){
                        if(nums2[ind]>nums2[j]){
                            ans.push_back(nums2[ind]);
                            found=true;
                            break;
                        }
                        else{
                            ind++;
                        }
                    }
                    if(found!=true){
                        ans.push_back(-1);
                    }
                    
                }
            }
        }
    return ans;
    }
};

Absolutely — here are **quick-glance commented notes** for LeetCode 496 that focus on **how to THINK**, not just memorize the code.

```cpp
/*
===========================================================
        LEETCODE 496 - NEXT GREATER ELEMENT I
===========================================================

PROBLEM:
--------
nums1 is a subset of nums2.

For every element x in nums1:
    1. Find x in nums2.
    2. Look to the RIGHT of x in nums2.
    3. Find the FIRST element > x.
    4. If none exists → -1.

Example:

nums1 = [4,1,2]
nums2 = [1,3,4,2]

4 → -1
1 → 3
2 → -1

Answer = [-1,3,-1]


===========================================================
BRUTE FORCE IDEA:
===========================================================

For every nums1[i]:

    → Find nums1[i] inside nums2
    → Once found at index j
    → Search nums2[j+1 ... end]
    → First element > nums2[j] is the answer
    → If nothing greater → -1

BUT:
------
This repeatedly searches to the right.

Can we avoid repeated searching?

YES → Use a MONOTONIC STACK.


===========================================================
KEY STACK IDEA:
===========================================================

Instead of asking:

    "For this element, what is greater to my RIGHT?"

Process nums2 from:

    RIGHT → LEFT

Why?

Because when we are at nums2[i],
everything already processed is to its RIGHT.

So the stack stores useful elements from the RIGHT.


===========================================================
STACK LOGIC:
===========================================================

For current element x = nums2[i]:

    while stack is NOT empty
    AND stack.top() <= x:

        pop()

WHY POP?

Because if:

    stack.top() <= x

then that element can NEVER be the
"next greater element" for x.

It is not greater than x.

So it is useless → remove it.


After removing useless elements:

    if stack is empty:
        answer = -1

    else:
        answer = stack.top()

WHY stack.top()?

Because after removing all elements <= x,
the top is the closest useful greater element
on the right.


Finally:

    push x

WHY PUSH x?

Because x may be the next greater element
for an element that comes BEFORE x.


===========================================================
EXAMPLE:
===========================================================

nums2 = [1, 3, 4, 2]

Process RIGHT → LEFT:


x = 2

    stack = []

    nothing greater exists

    answer[2] = -1

    push 2

    stack = [2]


x = 4

    stack = [2]

    2 <= 4 → pop

    stack = []

    no greater element

    answer[4] = -1

    push 4

    stack = [4]


x = 3

    stack = [4]

    4 <= 3? NO

    stack.top() = 4

    answer[3] = 4

    push 3

    stack = [4,3]


x = 1

    stack = [4,3]

    3 <= 1? NO

    stack.top() = 3

    answer[1] = 3

    push 1

    stack = [4,3,1]


Therefore:

    1 → 3
    3 → 4
    4 → -1
    2 → -1


===========================================================
WHY DO WE NEED A MAP?
===========================================================

We calculated the answer for EVERY element in nums2.

So store:

    nextGreater[1] = 3
    nextGreater[3] = 4
    nextGreater[4] = -1
    nextGreater[2] = -1

Then nums1 is easy.

For every x in nums1:

    ans.push_back(nextGreater[x]);


Example:

    nums1 = [4,1,2]

    nextGreater[4] → -1
    nextGreater[1] → 3
    nextGreater[2] → -1

    answer = [-1,3,-1]


===========================================================
CODE:
===========================================================
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1,
                                   vector<int>& nums2) {

        stack<int> st;

        // Stores:
        // element → its next greater element
        unordered_map<int, int> nextGreater;

        // Process nums2 from RIGHT → LEFT
        for (int i = nums2.size() - 1; i >= 0; i--) {

            // Remove elements that are NOT useful.
            // If top <= current, top can never be
            // the next greater element of current.
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // After removing useless elements:
            // Empty stack → no greater element exists
            if (st.empty()) {
                nextGreater[nums2[i]] = -1;
            }
            else {
                // Top is the next greater element
                nextGreater[nums2[i]] = st.top();
            }

            // Current element may be useful for
            // elements to its LEFT.
            st.push(nums2[i]);
        }

        // Build answer for nums1 using the map
        vector<int> ans;

        for (int x : nums1) {
            ans.push_back(nextGreater[x]);
        }

        return ans;
    }
};


/*
===========================================================
        QUICK GLANCE / MEMORY TRICK
===========================================================

"NEXT GREATER TO RIGHT"

            ↓

Process RIGHT → LEFT

            ↓

Remove useless elements:

    while (!st.empty() && st.top() <= current)
        st.pop();

            ↓

What's left?

    empty      → -1
    not empty  → st.top()

            ↓

Push current.

            ↓

Store answer in map.

            ↓

Use map to answer nums1.


===========================================================
MOST IMPORTANT "WHY" POINTS
===========================================================

WHY RIGHT → LEFT?
-----------------
Because then the elements already processed
are exactly the elements to the RIGHT of current.


WHY POP?
--------
top <= current

→ top is not greater than current
→ can never be the answer
→ useless
→ pop it


WHY TOP?
--------
After removing all useless elements,
the top is a greater element on the right.


WHY PUSH CURRENT?
-----------------
Current may be the next greater element
for an element to its LEFT.


WHY MAP?
--------
We calculate NGE for all nums2 elements once.

Then simply lookup answers for nums1.


===========================================================
IMPORTANT STACK PATTERN
===========================================================

For NEXT GREATER ELEMENT:

    RIGHT → LEFT

    while top <= current:
        pop

    if empty:
        answer = -1
    else:
        answer = top

    push current


REMEMBER:

    "POP SMALLER → TOP IS ANSWER → PUSH CURRENT"


===========================================================
COMPLEXITY
===========================================================

Each element is:

    pushed ONCE
    popped AT MOST ONCE

Therefore:

    Time  = O(nums2 + nums1)
    Space = O(nums2)

This is why stack is much better than
repeatedly searching to the right.
===========================================================
*/
```
