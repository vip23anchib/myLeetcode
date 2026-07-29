/*
=========================================================
796. Rotate String
=========================================================

QUESTION
--------
Given two strings s and goal,
return true if s can become goal after some
number of LEFT ROTATIONS.

One LEFT rotation means:

Take the first character
and move it to the end.

Example

abcde
↓
bcdea
↓
cdeab
↓
deabc
↓
eabcd
↓
abcde

=========================================================
APPROACH
=========================================================

Step 1

If lengths are different

Impossible.

Return false.

---------------------------------------------------------

Step 2

Repeat n times

Rotate string once.

After every rotation

Check

s == goal ?

If yes

Return true.

---------------------------------------------------------

Step 3

After trying all possible rotations

Return false.


=========================================================
HOW TO ROTATE ONE TIME?
=========================================================

Example

s = "abcde"

Store first character

first = 'a'

Remove first character

bcde

Append first character

bcdea

Exactly one left rotation.


=========================================================
DRY RUN
=========================================================

s = "abcde"

goal = "cdeab"

Rotation 0

abcde

Not equal

-----------------------------------

Rotation 1

bcdea

Not equal

-----------------------------------

Rotation 2

cdeab

Equal

Return true.


=========================================================
WHY ONLY n ROTATIONS?
=========================================================

Example

abcde

1

bcdea

2

cdeab

3

deabc

4

eabcd

5

abcde

After n rotations

String becomes original again.

So checking beyond n rotations is useless.


=========================================================
TIME COMPLEXITY
=========================================================

Each rotation

erase()      -> O(n)

push_back()  -> O(1)

comparison   -> O(n)

Repeated n times

Overall

O(n²)


=========================================================
SPACE COMPLEXITY
=========================================================

O(1)

Only modifying the same string.


=========================================================
CODE
=========================================================
*/

class Solution {
public:
    bool rotateString(string s, string goal) {

        // Different lengths can never match
        if (s.length() != goal.length())
            return false;

        int n = s.length();

        // Try every possible rotation
        for (int i = 0; i < n; i++) {

            // Save first character
            char first = s[0];

            // Remove first character
            s.erase(s.begin());

            // Put it at the end
            s.push_back(first);

            // Check after this rotation
            if (s == goal)
                return true;
        }

        return s == goal;
    }
};
