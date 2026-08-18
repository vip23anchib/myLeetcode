class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {

            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
            
                if (st.empty()) {
                    return false;
                }

                if (ch == ')' && st.top() == '(') {
                    st.pop();
                }
                else if (ch == '}' && st.top() == '{') {
                    st.pop();
                }
                else if (ch == ']' && st.top() == '[') {
                    st.pop();
                }
                else {
                   
                    return false;
                }
            }
        }

        return st.empty();
    }
};

/*
==========================================================
        IMPORTANT: stack.top() ON EMPTY STACK
==========================================================

stack<char> st;

IMPORTANT:
----------
st.top() does NOT return -1 when the stack is empty.

If:
    st = empty

then:
    st.top()

is an INVALID operation → Undefined Behavior.
It may crash / do anything. It does NOT become false or -1.


WHY DO WE CHECK st.empty() FIRST?
---------------------------------

Suppose input is:

    s = ")"

Stack is empty because we haven't pushed any opening bracket.

If we directly write:

    if (ch == ')' && st.top() == '(')

Then:

    ch == ')'              → true

So C++ MUST evaluate:

    st.top() == '('

But st.top() doesn't exist because stack is empty!

Therefore → INVALID ACCESS.


So ALWAYS do:

    if (st.empty()) {
        return false;
    }

BEFORE using:

    st.top()


==========================================================
        TWO DIFFERENT REASONS FOR return false
==========================================================

1. EMPTY STACK:

    if (st.empty()) {
        return false;
    }

    Meaning:
    "There is NOTHING available to match this closing bracket."


2. WRONG MATCH:

    else {
        return false;
    }

    Meaning:
    "There IS an opening bracket,
     but it is the WRONG type."


Example 1:
----------

Input:
    ")"

Stack:
    empty

Flow:

    ')' 
     ↓
    opening bracket? NO
     ↓
    st.empty()? YES
     ↓
    return false


Example 2:
----------

Input:
    "(]"

After '(':

    stack = ['(']

Now current character = ']'

Flow:

    opening bracket? NO
     ↓
    st.empty()? NO
     ↓
    check matching brackets
     ↓
    '(' does NOT match ']'
     ↓
    final else
     ↓
    return false


==========================================================
        IMPORTANT C++ CONCEPT: && SHORT-CIRCUITING
==========================================================

For:

    if (ch == ')' && st.top() == '(')

C++ evaluates LEFT → RIGHT.

If:

    ch == ')'

is FALSE,

then C++ does NOT evaluate st.top().

But if:

    ch == ')'

is TRUE,

C++ MUST evaluate:

    st.top()

Therefore:

    ch = ')' + empty stack
          ↓
    true && st.top()
          ↓
    st.top() is invalid
          ↓
    Undefined Behavior


==========================================================
        QUICK MEMORY
==========================================================

st.top()
    ↓
Returns the top ELEMENT.

It does NOT return:
    ❌ -1
    ❌ false
    ❌ NULL

If stack is empty:
    st.top() → INVALID / Undefined Behavior

Therefore:

    if (st.empty())
        return false;

    // NOW it is safe:
    st.top();


Think:

    empty() → "Does an element exist?"
    top()   → "Give me that element."

ALWAYS check existence before asking for the element.
==========================================================
*/
