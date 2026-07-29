/*
=========================================================
1021. Remove Outermost Parentheses
=========================================================

QUESTION
--------
A valid parentheses string is made of one or more primitive
parentheses strings.

For EVERY primitive:
    Remove its first '(' and its last ')'.

Return the final string.

Example:
Input : "(()())(())"
Primitives:
    (()())   (())

After removing outermost pair:
    ()()     ()

Output:
    "()()()"


=========================================================
THINKING PROCESS
=========================================================

Brute Force Thought:
--------------------
1. Find each primitive separately.
2. Remove first and last bracket.
3. Join everything.

But this is unnecessary.

Instead...

Observe:
--------
For every primitive

    ( ........ )

Only TWO brackets are removed:
    - first '('
    - last ')'

Everything inside remains.

So the real question becomes:

"How do I know whether the current bracket is the OUTERMOST one?"


=========================================================
KEY IDEA : NESTING DEPTH (open)
=========================================================

Maintain:

    open = current nesting depth

Meaning:

open = 0
    We are outside every primitive.

open = 1
    Inside one pair.

open = 2
    Inside two nested pairs.

open = 3
    Inside three nested pairs.

Example:

String = "(()())"

Character      open(after)
--------------------------
(                 1
(                 2
)                 1
(                 2
)                 1
)                 0


=========================================================
HOW TO IDENTIFY OUTERMOST '('
=========================================================

Suppose

open = 0

Read '('

Depth changes

    0 -> 1

This means

"We were outside.
This bracket STARTED a new primitive."

Therefore this '(' is the OUTERMOST '('.

=> Skip it.

---------------------------------------------------------

If instead

open = 2

Read '('

Depth becomes

    2 -> 3

We were already inside another pair.

This is NOT outermost.

=> Keep it.

Rule:

For '('

    if(open > 0)
        keep it;

    open++;

(Remember: Check BEFORE increasing depth.)


=========================================================
HOW TO IDENTIFY OUTERMOST ')'
=========================================================

Suppose

Before reading ')'

open = 1

After closing

open = 0

Depth changes

    1 -> 0

This bracket CLOSED the primitive.

Therefore this ')' is OUTERMOST.

=> Skip it.

---------------------------------------------------------

If instead

Before reading ')'

open = 3

After closing

open = 2

We're still inside another pair.

This ')' is NOT outermost.

=> Keep it.

Rule:

For ')'

    open--;

    if(open > 0)
        keep it;

(Remember: Check AFTER decreasing depth.)


=========================================================
WHY DIFFERENT ORDER?
=========================================================

For '('

We want to know:

"Was I already inside?"

So check BEFORE open++.

---------------------------------------------------------

For ')'

We want to know:

"Am I still inside after closing?"

So check AFTER open--.


=========================================================
INTERVIEW MEMORY TRICK
=========================================================

Think in terms of depth transitions.

0 -> 1
    = Starting a primitive
    = Skip '('

1 -> 0
    = Ending a primitive
    = Skip ')'

Anything else

1 -> 2
2 -> 3
3 -> 2
2 -> 1

means we're INSIDE the primitive.

=> Keep those brackets.


=========================================================
TIME COMPLEXITY
=========================================================

O(n)

One pass through the string.


=========================================================
SPACE COMPLEXITY
=========================================================

O(n)

For the answer string.


=========================================================
CODE
=========================================================
*/

class Solution {
public:
    string removeOuterParentheses(string s) {

        string ans = "";

        // Current nesting depth
        int open = 0;

        for(char c : s){

            if(c == '('){

                // If depth > 0,
                // we're already inside another pair,
                // so this '(' is NOT outermost.
                if(open > 0)
                    ans += c;

                // Increase nesting depth
                open++;
            }
            else{

                // Close one open bracket
                open--;

                // If depth is still > 0,
                // we're still inside the primitive,
                // so this ')' is NOT outermost.
                if(open > 0)
                    ans += c;
            }
        }

        return ans;
    }
};


};
// Mental trick to remember forever

// Think of open as the current nesting depth.

// For '(':
// Depth 0 → 1 means you're entering a new primitive → skip it.
// Depth 1 → 2, 2 → 3, ... means you're already inside → keep it.
// For ')':
// Depth 1 → 0 means you're leaving the primitive → skip it.
// Depth 3 → 2, 2 → 1, ... means you're still inside → keep it.

// If you remember "0→1 starts a primitive, 1→0 ends a primitive", you'll be able to derive this solution during an interview without memorizing the code.
