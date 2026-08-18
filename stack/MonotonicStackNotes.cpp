/*
MONOTONIC STACK
----------------

Normal stack:
    No ordering required.

Monotonic stack:
    Stack is maintained in increasing
    OR decreasing order.

WHY?
    Remove elements that can never
    be useful → keeps only useful candidates.

NEXT GREATER ELEMENT:
    Process RIGHT → LEFT

    while (!st.empty() && st.top() <= current)
        st.pop();

    // smaller/equal elements are useless

    if (!st.empty())
        answer = st.top();

    st.push(current);

This creates a MONOTONICALLY DECREASING stack:

    9
    7
    5
    3

Remember:
    "Need GREATER → remove smaller/equal."
*/


// There are two common types
// Monotonically increasing stack
// 1
// 3
// 5
// 8

// You usually pop when:

// st.top() > current

// because you're trying to maintain increasing order.

// Commonly useful for things like Next Smaller Element.

// Monotonically decreasing stack
// 9
// 7
// 5
// 2

// You usually pop when:

// st.top() < current

// or <= depending on the problem.

// Commonly useful for Next Greater Element.
