/*
=========================================================
205. Isomorphic Strings
=========================================================

QUESTION
--------
Given two strings s and t,
determine whether they are isomorphic.

Definition:
Characters in s can be replaced to get t.

Rules:
1. One character must always map to the SAME character.
2. Two different characters CANNOT map to the same character.
3. A character CAN map to itself.

---------------------------------------------------------

Example 1

s = "egg"
t = "add"

Mapping

e -> a
g -> d

Result = true

---------------------------------------------------------
=========================================================
THINKING PROCESS
=========================================================

The question is NOT asking whether the letters are equal.
It is asking whether the MAPPING between letters is valid.

Think of every character as a person.

Example

a ----> x

Once this relation is created,

a can NEVER point to another letter.

Wrong

a -> x
a -> y

---------------------------------------------------------

Also,

Two different letters cannot point to the same letter.

Wrong

a -> x
b -> x

Therefore the mapping must be

ONE TO ONE.


=========================================================
WHY ONE HASHMAP IS NOT ENOUGH?
=========================================================

Suppose

s = "ab"
t = "aa"

Using only

a -> a
b -> a

A single hashmap thinks everything is fine.

But actually

'a' is already used.

Two letters are mapping to the same character.

Therefore ONE hashmap cannot detect this.


=========================================================
KEY IDEA
=========================================================

Use TWO hashmaps.

Map 1

s -> t

Example

a -> x
b -> y

-----------------------------------

Map 2

t -> s

Example

x -> a
y -> b

Now every mapping is unique.


=========================================================
ALGORITHM
=========================================================

For every index i

Look at

s[i]
t[i]

CASE 1

Neither character has appeared before.

Create mapping.

sMap[s[i]] = t[i]
tMap[t[i]] = s[i]

---------------------------------------------------------

CASE 2

Mapping already exists.

Verify

sMap[s[i]] == t[i]

AND

tMap[t[i]] == s[i]

If either check fails

return false.

If loop finishes

return true.

=========================================================
VISUAL MEMORY TRICK
=========================================================

Think of every character as having ONE partner.

Allowed

a ----> x
b ----> y
c ----> z

Not allowed

a ----> x
a ----> y

OR

a ----> x
b ----> x

Every character should have exactly ONE unique partner.


=========================================================
TIME COMPLEXITY
=========================================================

O(n)

One pass through both strings.

Hashmap operations are O(1).


=========================================================
SPACE COMPLEXITY
=========================================================

O(1)

At most 256 characters (ASCII) or a fixed-size alphabet,
so the extra space is bounded.

(If considering all possible characters in theory,
you may also see this written as O(k), where k is the
number of distinct characters.)


=========================================================
CODE
=========================================================
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // Different lengths can never be isomorphic
        if (s.size() != t.size())
            return false;

        // s character -> t character
        unordered_map<char, char> sMap;

        // t character -> s character
        unordered_map<char, char> tMap;

        for (int i = 0; i < s.size(); i++) {

            // First time seeing BOTH characters
            if (!sMap.count(s[i]) && !tMap.count(t[i])) {

                // Create mapping in both directions
                sMap[s[i]] = t[i];
                tMap[t[i]] = s[i];
            }
            else {

                // Mapping already exists.
                // Verify it is still the same.

                if (sMap[s[i]] != t[i] ||
                    tMap[t[i]] != s[i])
                    return false;
            }
        }

        return true;
    }
};

/*
=========================================================
INTERVIEW THINKING
=========================================================

Question asks:

Can one thing consistently map to another?

↓

Need a HashMap.

---------------------------------------------------------

Question also says:

No two things can map to the same value.

↓

Need another HashMap.

---------------------------------------------------------

Pattern:

One-to-One Mapping

↓

Use TWO hashmaps.

(s -> t)

and

(t -> s)

This pattern appears in:

✔ Isomorphic Strings
✔ Word Pattern
✔ Pattern Matching
✔ Character Replacement
✔ Encoding / Decoding problems

=========================================================
10-SECOND REVISION
=========================================================

For every character pair

s[i] <-------> t[i]

If both are new
    -> Create mapping.

Else
    -> Verify existing mapping.

If mapping breaks
    -> return false.

Else

return true.
=========================================================
*/
