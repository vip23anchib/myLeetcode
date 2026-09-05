// ============================================================
// ALL SUBSEQUENCES WITH SUM K
// PICK / NOT-PICK RECURSION
// ============================================================
//
// PROBLEM:
// Given an array, print all subsequences whose sum is equal to K.
//
// Example:
// arr = {1, 2, 1}
// K = 2
//
// Valid subsequences:
// {1, 1}
// {2}
//
// ------------------------------------------------------------
// CORE IDEA:
// ------------------------------------------------------------
//
// At every index, we have 2 choices:
//
//      1. PICK the current element
//      2. NOT PICK the current element
//
// Therefore, recursion creates all possible subsequences.
//
//
// Example for {1,2,1}:
//
//                    []
//                  /    \
//              PICK 1   NOT PICK 1
//                /          \
//            PICK 2        NOT PICK 2
//             /  \           /  \
//           ...  ...       ...  ...
//
// Every path from the root to the end represents
// one possible subsequence.
//
//
// ------------------------------------------------------------
// PARAMETERS:
// ------------------------------------------------------------
//
// ind:
//     Current index we are processing.
//
// ds:
//     Data structure (vector) containing the current
//     subsequence we have picked.
//
// s:
//     Sum of the elements currently present in ds.
//
// sum:
//     Target sum K.
//
// arr:
//     Original array.
//
// n:
//     Size of the array.
//
//
// ------------------------------------------------------------
// BASE CASE:
// ------------------------------------------------------------
//
// if (ind == n)
//
//     We have reached the end of the array.
//     This means we have made a PICK / NOT-PICK decision
//     for every element.
//
//     Now check:
//
//         if (s == sum)
//
//     If the current subsequence has the required sum,
//     print it.
//
//     Then return because there are no more elements
//     to process.
//
//
// ------------------------------------------------------------
// PICK CASE:
// ------------------------------------------------------------
//
// ds.push_back(arr[ind]);
//
//     Add the current element to our subsequence.
//
// s += arr[ind];
//
//     Add the current element to the current sum.
//
// solve(ind + 1, ...);
//
//     Move to the next index and continue making choices.
//
//
// ------------------------------------------------------------
// BACKTRACKING / UNDO:
// ------------------------------------------------------------
//
// After completely exploring the PICK branch:
//
//     s -= arr[ind];
//     ds.pop_back();
//
// We undo the choice we just made.
//
// Why?
//
// Because now we want to explore the NOT-PICK branch.
//
// We need to restore ds and s to exactly the state
// they were in before we picked arr[ind].
//
//
// This is called BACKTRACKING.
//
//
//
// The pattern is:
//
//     PICK
//       ↓
//     RECURSE
//       ↓
//     UNDO
//       ↓
//     NOT PICK
//       ↓
//     RECURSE
//
//
// ------------------------------------------------------------
// NOT-PICK CASE:
// ------------------------------------------------------------
//
// solve(ind + 1, ds, s, sum, arr, n);
//
// We don't add arr[ind] to ds.
//
// We don't change s.
//
// We simply move to the next index.
//
//
// ------------------------------------------------------------
// IMPORTANT RECURSION TEMPLATE:
// ------------------------------------------------------------
//
//     // PICK
//     ds.push_back(arr[ind]);
//     s += arr[ind];
//
//     solve(ind + 1, ds, s, sum, arr, n);
//
//     // BACKTRACK
//     s -= arr[ind];
//     ds.pop_back();
//
//     // NOT PICK
//     solve(ind + 1, ds, s, sum, arr, n);
//
//
// ------------------------------------------------------------
// WHY DO WE NEED ds AND s?
// ------------------------------------------------------------
//
// ds:
//     Stores the actual subsequence currently being built.
//
// s:
//     Stores the sum of that subsequence.
//
// Example:
//
//     ds = {1, 2}
//
//     s = 3
//
// Instead of calculating the sum of ds again and again,
// we maintain s while making choices.
//
// When we PICK:
//
//     s += arr[ind]
//
// When we UNDO:
//
//     s -= arr[ind]
//
//
// ------------------------------------------------------------
// WHY DO WE POP BACK?
// ------------------------------------------------------------
//
// Suppose:
//
//     ds = {1}
//
// We PICK 2:
//
//     ds = {1, 2}
//
// We explore all possibilities from here.
//
// After returning from recursion, we need to go back
// to the previous state:
//
//     ds = {1}
//
// Therefore:
//
//     ds.pop_back();
//
// removes the 2.
//
// Similarly:
//
//     s -= arr[ind];
//
// removes 2 from the current sum.
//
//
// This allows us to explore the other possibility:
//
//     NOT PICK 2
//
//
// ------------------------------------------------------------
// COMPLETE FLOW:
// ------------------------------------------------------------
//
// For every element:
//
//             arr[ind]
//             /      \
//          PICK      NOT PICK
//           |           |
//        add it      don't add
//           |           |
//        update s      s unchanged
//           |           |
//        recurse      recurse
//           |
//        BACKTRACK
//           |
//      remove element
//      restore sum
//
//
// ------------------------------------------------------------
// BASE CASE IS WHERE WE CHECK THE ANSWER:
// ------------------------------------------------------------
//
// if (ind == n) {
//
//     if (s == sum) {
//
//         // current ds is a valid answer
//     }
//
//     return;
// }
//
// We only print when we have reached the end AND
// the current subsequence has sum K.
//
//
// ------------------------------------------------------------
// TIME COMPLEXITY:
// ------------------------------------------------------------
//
// Every element has 2 choices:
//
//     PICK / NOT PICK
//
// Therefore there are:
//
//     2^n
//
// possible subsequences.
//
// At each leaf, printing a subsequence can take up to O(n).
//
// Therefore:
//
//     Time = O(n * 2^n)
//
// If we only consider the recursion tree itself:
//
//     Number of states = O(2^n)
//
//
//
// SPACE COMPLEXITY:
// ------------------------------------------------------------
//
// Recursion depth = O(n)
//
// Current subsequence ds = O(n)
//
// If we are only printing the answers and not storing them:
//
//     Auxiliary space = O(n)
//
//
//
// ------------------------------------------------------------
// MOST IMPORTANT THING TO REMEMBER:
// ------------------------------------------------------------
//
// Every element gives us exactly TWO choices:
//
//             TAKE
//               OR
//             SKIP
//
// The standard backtracking pattern is:
//
//     PICK → RECURSE → UNDO → NOT PICK → RECURSE
//
// Once this pattern is understood, it can be used for
// many other recursion and backtracking problems.


#include <bits/stdc++.h>
using namespace std;

void printS(int ind, vector<int>& ds, int s, int sum, int arr[], int n)
{
    // Base case:
    // All elements have been considered
    if (ind == n)
    {
        // Check whether current subsequence has sum K
        if (s == sum)
        {
            // Print the current subsequence
            for (auto it : ds)
                cout << it << " ";

            cout << endl;
        }

        return;
    }

    // PICK the current element
    ds.push_back(arr[ind]);
    s += arr[ind];

    // Move to the next element
    printS(ind + 1, ds, s, sum, arr, n);

    // BACKTRACK:
    // Undo the PICK
    s -= arr[ind];
    ds.pop_back();

    // NOT PICK the current element
    printS(ind + 1, ds, s, sum, arr, n);
}
