// RECURSION / BACKTRACKING APPROACH
//
// IDEA:
// At every element, we have exactly 2 choices:
//
// 1. TAKE the element
// 2. DON'T TAKE the element
//
// Example:
// arr = [1, 2, 3]
//
//                         []
//                       /    \
//                    TAKE    SKIP
//                     1        1
//                    /          \
//                 TAKE          SKIP
//                  2              2
//                 / \            / \
//              TAKE SKIP      TAKE SKIP
//                3     3        3     3
//
// Every path from the root to a leaf represents
// one complete subsequence.
//
// We use two important variables:
//
// i:
// Tells us which element we are currently deciding about.
//
// current:
// Stores the elements we have selected so far.
//
// result:
// Stores all the completed subsequences.
//
// BASE CASE:
//
// When:
//
//     i == arr.size()
//
// it means we have made a TAKE/SKIP decision
// for every element.
//
// Therefore, current is one complete subsequence.
//
// We save it:
//
//     result.push_back(current);
//
//
//
// RECURSIVE CASE:
//
// At every index we make two choices.
//
// CHOICE 1: TAKE arr[i]
//
//     current.push_back(arr[i]);
//     solve(i + 1, ...);
//
// We add the element and recursively solve
// the remaining elements.
//
//
//
// Then we UNDO the choice:
//
//     current.pop_back();
//
// Why?
//
// Because we are going to explore the other choice:
// DON'T TAKE arr[i].
//
// We need current to return to the state
// it was in before we chose arr[i].
//
//
//
// CHOICE 2: DON'T TAKE arr[i]
//
//     solve(i + 1, ...);
//
// We simply move to the next element
// without adding arr[i].
//
//
//
// IMPORTANT PATTERN:
//
//     TAKE
//       ↓
//     RECURSE
//       ↓
//     UNDO
//       ↓
//     SKIP
//       ↓
//     RECURSE
//
// This is the fundamental BACKTRACKING pattern.
//
//
//
// WHY current AND result?
//
// current = ONE subsequence currently being built.
//
// result = ALL completed subsequences.
//
// Example:
//
//     current = [1, 3]
//
// is ONE answer.
//
//     result = {
//         [1,2,3],
//         [1,2],
//         [1,3],
//         ...
//     }
//
// contains ALL answers.
//
//
//
// WHY current.copy() / result.push_back(current)?
//
// At the base case, current represents one completed
// subsequence, so we save a copy of it into result.
//
// In C++:
//
//     result.push_back(current);
//
// copies the current vector into result.
//
//
//
// TIME COMPLEXITY:
//
// There are 2^n possible subsequences.
// Each subsequence can contain up to n elements.
//
// Time = O(n * 2^n)
//
// SPACE = O(n * 2^n) when storing all answers.
//
//
//
// KEY THING TO REMEMBER:
//
// Recursion is simply:
//
//     Every element -> TAKE or SKIP
//
//     TAKE  -> append -> recurse -> pop
//     SKIP  -> recurse


#include <bits/stdc++.h>
using namespace std;

void solve(
    int i,
    vector<int>& arr,
    vector<int>& current,
    vector<vector<int>>& result
) {

    // BASE CASE:
    // We have made a decision for every element
    if (i == arr.size()) {

        // Save the current subsequence
        result.push_back(current);

        return;
    }

    // -------------------------
    // CHOICE 1: TAKE arr[i]
    // -------------------------

    current.push_back(arr[i]);

    // Move to the next element
    solve(i + 1, arr, current, result);

    // Undo the choice
    current.pop_back();


    // -------------------------
    // CHOICE 2: DON'T TAKE arr[i]
    // -------------------------

    // Move to the next element without adding arr[i]
    solve(i + 1, arr, current, result);
}


vector<vector<int>> getSubsequences(vector<int>& arr) {

    vector<vector<int>> result;

    vector<int> current;

    // Start from index 0
    solve(0, arr, current, result);

    return result;
}
