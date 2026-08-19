/*
LeetCode 1423 - Maximum Points You Can Obtain from Cards

PROBLEM:
- Can take exactly k cards.
- Each card must be taken from either the LEFT or RIGHT end.
- Goal: maximize total score.


--------------------------------------------------
1. MY FIRST / GREEDY APPROACH
--------------------------------------------------

Idea:
    At every step:
        if(left card > right card)
            take left
        else
            take right

Why I thought it should work:
    "Take the bigger card available right now."

Example:
    [1, 2, 3, 4, 5, 6, 1]
              ^        ^
            left     right

    Compare the two ends and take the bigger one.


--------------------------------------------------
2. WHY THIS GREEDY APPROACH FAILS
--------------------------------------------------

The problem is:
    Choosing the biggest card NOW does NOT guarantee
    the biggest TOTAL score.

Why?

    Taking a card changes the future choices.

Example:
    [1, 100, 1, 1, 100]
     ^             ^
    left          right

    k = 3

A greedy choice only asks:
    "Which end is bigger RIGHT NOW?"

But the real question is:
    "Which choice gives me the best TOTAL after all k picks?"

An early smaller choice may expose a much bigger card later.

Therefore:

    local best choice != guaranteed global best

This is when I should become suspicious of greedy.


--------------------------------------------------
3. HOW TO DETECT THAT GREEDY MAY FAIL
--------------------------------------------------

Whenever I think:

    "I'll just take the best option available right now."

STOP and ask:

    1. Does my current choice affect future choices?
    2. Could taking a smaller option now expose a much
       better option later?
    3. Can I PROVE that taking the locally best option
       is always safe?

If I cannot prove that the local choice is always part
of an optimal solution, I should NOT blindly use greedy.

Important:
    Greedy is not wrong just because there are future
    choices.

    Greedy is valid when we can justify/prove that the
    local best choice can always lead to an optimal answer.

Here, we cannot prove that.


--------------------------------------------------
4. LOOK AT THE PROBLEM DIFFERENTLY
--------------------------------------------------

We must take EXACTLY k cards.

Every card comes from:
    LEFT or RIGHT

Instead of thinking:

    "At every step, should I choose L or R?"

think:

    "How many cards will I finally take from the LEFT?"

Suppose:
    x = number of cards taken from LEFT

Since total cards taken must be k:

    left + right = k

Therefore:

    right = k - x


--------------------------------------------------
5. TRY ALL POSSIBLE SPLITS
--------------------------------------------------

If k = 3:

    0 from left -> 3 from right
    1 from left -> 2 from right
    2 from left -> 1 from right
    3 from left -> 0 from right

So instead of considering all possible L/R sequences,
we only need to check:

    x = 0, 1, 2, ..., k

There are only k + 1 possibilities.


--------------------------------------------------
6. WHY THIS IS ENOUGH
--------------------------------------------------

Suppose:

    x = 2 cards from left
    k-x = 1 card from right

Because cards can ONLY be taken from the ends:

    taking 2 from left means the FIRST 2 cards
    taking 1 from right means the LAST 1 card

So the final combination is completely determined.

We don't need to care about the order:

    LLR
    LRL
    RLL

All result in the same final set:
    2 cards from left + 1 card from right.


--------------------------------------------------
7. OPTIMIZE THE CALCULATION
--------------------------------------------------

We could calculate every split separately,
but that would repeatedly calculate sums.

Instead:

    Start by taking all k cards from the LEFT.

Example:

    [1,2,3,4,5,6,1]
     ^^^^^
     k = 3

Initial score:
    1 + 2 + 3 = 6

This represents:

    3 LEFT + 0 RIGHT


Then gradually replace LEFT cards with RIGHT cards.


Step 1:
    3L + 0R
        ↓
    2L + 1R

    Remove 3
    Add 1

    score = 6 - 3 + 1 = 4


Step 2:
    2L + 1R
        ↓
    1L + 2R

    Remove 2
    Add 6

    score = 4 - 2 + 6 = 8


Step 3:
    1L + 2R
        ↓
    0L + 3R

    Remove 1
    Add 5

    score = 8 - 1 + 5 = 12


Check maximum:

    max(6, 4, 8, 12) = 12


--------------------------------------------------
8. FINAL APPROACH
--------------------------------------------------

1. Calculate sum of first k cards.
   -> This is the case: k LEFT + 0 RIGHT.

2. Set maxScore = currentScore.

3. Start from the last of those k left cards.

4. One by one:
       remove one card from LEFT
       add one card from RIGHT

5. After every replacement:
       update maxScore.

6. Return maxScore.


--------------------------------------------------
9. CODE
--------------------------------------------------

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        // Start with k cards from the left
        int currentScore = 0;

        for(int i = 0; i < k; i++) {
            currentScore += cardPoints[i];
        }

        int maxScore = currentScore;

        // Replace left cards with right cards
        int right = n - 1;

        for(int i = k - 1; i >= 0; i--) {

            // Remove one card from left
            currentScore -= cardPoints[i];

            // Add one card from right
            currentScore += cardPoints[right];

            right--;

            // Keep best score seen so far
            maxScore = max(maxScore, currentScore);
        }

        return maxScore;
    }
};


/--------------------------------------------------
10. COMPLEXITY
--------------------------------------------------

Initial sum:
    O(k)

Replacement loop:
    O(k)

Total:
    O(k)

Extra space:
    O(1)


--------------------------------------------------
11. KEY TAKEAWAY
--------------------------------------------------

My original mistake:

    "Take the biggest card RIGHT NOW."

Correct thinking:

    "What are all possible final combinations?"

Since exactly k cards must be taken:

    x cards from LEFT
    k-x cards from RIGHT

Try every x from 0 to k.

Then optimize by starting with all k from left
and swapping them with right cards one at a time.

IMPORTANT PATTERN TO REMEMBER:

    When greedy says:
        "Take the best option right now"

    Ask:
        "Can I construct a counterexample where taking
         the locally best option hurts the final answer?"

    If yes -> greedy is NOT reliable.

    Look for another way to represent all possible
    choices more efficiently.
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        // Start by taking all k cards from the left
        int currentScore = 0;

        for(int i = 0; i < k; i++) {
            currentScore += cardPoints[i];
        }

        int maxScore = currentScore;

        // Now gradually replace left cards with right cards
        int right = n - 1;

        for(int i = k - 1; i >= 0; i--) {

            // Remove one card from the left
            currentScore -= cardPoints[i];

            // Add one card from the right
            currentScore += cardPoints[right];

            right--;

            maxScore = max(maxScore, currentScore);
        }

        return maxScore;
    }
};
