/*
    STACK USING 2 QUEUES
    --------------------

    Stack = LIFO  → Last In First Out
    Queue = FIFO  → First In First Out

    Idea:
    Keep q1 arranged like a STACK.

    Example:
        q1 = [30, 20, 10]
               ↑
              front

        So:
        q1.front() = stack TOP


    PUSH(x):
    --------
    We want the NEW element at the FRONT of q1.

    Example:
        q1 = [20, 10]

        push(30)

        1. Put 30 into q2
              q2 = [30]

        2. Move all elements from q1 to q2
              q2 = [30, 20, 10]

        3. Swap q1 and q2
              q1 = [30, 20, 10]
              q2 = empty

        Now q1.front() = 30 = stack TOP


    POP():
    ------
    Since q1 is already arranged like a stack,
    simply remove q1.front().

        q1 = [30, 20, 10]

        pop() → 30

        q1 = [20, 10]


    TOP():
    -------
    Simply return q1.front().
    Don't remove it.


    EMPTY:
    ------
    q1.empty()


    IMPORTANT:
    ----------
    q2 is only a TEMPORARY queue used during push.

    After every push:
        q1 = stack order
        q2 = empty


    TIME COMPLEXITY:
    ----------------
    push() → O(n)   // move all old elements
    pop()  → O(1)
    top()  → O(1)
    empty() → O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class MyStack {

    queue<int> q1;
    queue<int> q2;

public:

    // PUSH: Make new element come to FRONT of q1
    void push(int x) {

        // 1. Put new element in q2
        q2.push(x);

        // 2. Move all old elements behind x
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // 3. q2 now has correct stack order
        //    Make q1 the main queue
        swap(q1, q2);
    }

    // POP: Top of stack = front of q1
    int pop() {

        if (q1.empty()) {
            return -1;
        }

        int x = q1.front();
        q1.pop();

        return x;
    }

    // TOP: Look at top without removing
    int top() {

        if (q1.empty()) {
            return -1;
        }

        return q1.front();
    }

    // Check if stack is empty
    bool empty() {
        return q1.empty();
    }
};
