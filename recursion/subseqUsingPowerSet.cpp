// POWER SET / BITMASK APPROACH
//
// IDEA:
// Every element has 2 choices:
// 1. Take the element
// 2. Don't take the element
//
// For an array of size n:
// Number of possible subsequences = 2^n
//
// We use numbers from 0 to 2^n - 1.
// Each number represents one combination of TAKE/SKIP decisions.
//
// Example:
// arr = [1, 2, 3]
//
// mask = 0  -> 000 -> don't take anything -> []
// mask = 1  -> 001 -> take 1            -> [1]
// mask = 2  -> 010 -> take 2            -> [2]
// mask = 3  -> 011 -> take 1 and 2      -> [1,2]
// mask = 4  -> 100 -> take 3            -> [3]
// mask = 5  -> 101 -> take 1 and 3      -> [1,3]
// mask = 6  -> 110 -> take 2 and 3      -> [2,3]
// mask = 7  -> 111 -> take everything   -> [1,2,3]
//
// IMPORTANT:
// mask is actually an INTEGER.
// We use its binary representation to inspect its bits.
//
// Each bit corresponds to one array element:
//
// bit 0 -> arr[0]
// bit 1 -> arr[1]
// bit 2 -> arr[2]
// ...
//
// To check whether bit i is 1, we use:
//
//     mask & (1 << i)
//
// WHAT DOES (1 << i) DO?
//
// It creates a number where only bit i is 1.
//
// i = 0 -> 001
// i = 1 -> 010
// i = 2 -> 100
//
// '&' then checks whether that particular bit is set in mask.
//
// If:
//
//     mask & (1 << i) != 0
//
// then bit i is 1, so we TAKE arr[i].
//
// Otherwise, we SKIP arr[i].
//
// current:
// Stores the ONE subsequence we are currently building.
//
// result:
// Stores ALL the subsequences.
//
// For every mask:
//     1. Create an empty current subsequence.
//     2. Check every bit.
//     3. If bit i is 1, add arr[i] to current.
//     4. After checking all elements, add current to result.
//
// TIME COMPLEXITY:
// There are 2^n masks.
// For every mask, we check n elements.
//
// Time = O(n * 2^n)
//
// SPACE = O(n * 2^n) if we store all subsequences.


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> powerSet(vector<int>& arr) {
    int n = arr.size();

    vector<vector<int>> result;

    // There are 2^n possible subsequences
    for (int mask = 0; mask < (1 << n); mask++) {

        // Stores the current subsequence
        vector<int> current;

        // Check every element
        for (int i = 0; i < n; i++) {

            // Check if the i-th bit is 1
            if (mask & (1 << i)) {

                // If bit is 1, take arr[i]
                current.push_back(arr[i]);
            }
        }

        // Store this complete subsequence
        result.push_back(current);
    }

    return result;
}
