// ============================================================
// SUM OF SUBARRAY MINIMUMS
// ============================================================


// ============================================================
// APPROACH 1: BRUTE FORCE
// TC: O(N^2)
// SC: O(1)
// TLE for large input
// ============================================================

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    long long total = 0;
    int MOD = 1e9 + 7;

    // Fix the starting index
    for (int i = 0; i < n; i++) {

        int mini = INT_MAX;

        // Extend the subarray from i to j
        for (int j = i; j < n; j++) {

            // Keep updating minimum as subarray grows
            mini = min(mini, arr[j]);

            // Add minimum of current subarray
            total = (total + mini) % MOD;
        }
    }

    return total;
}

// WHY TLE?
// We consider every subarray -> O(N^2) subarrays.
// Although we update minimum in O(1), there can still be O(N^2)
// subarrays, which is too slow for large N.


// ============================================================
// APPROACH 2: MONOTONIC STACK
// TC: O(N)
// SC: O(N)
// ============================================================

// Instead of finding minimum for every subarray,
// find how many subarrays have arr[i] as their minimum.
//
// For every element:
// PSEE = Previous Smaller OR Equal Element
// NSE  = Next Smaller Element
//
// left  = i - PSEE[i]
// right = NSE[i] - i
//
// Number of subarrays where arr[i] is minimum:
// left * right
//
// Contribution:
// left * right * arr[i]


int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    const long long MOD = 1e9 + 7;

    vector<int> nse(n), psee(n);

    // --------------------------------------------------------
    // STEP 1: Find NSE (Next Smaller Element)
    // --------------------------------------------------------
    // Traverse from RIGHT -> LEFT.
    //
    // Pop elements which are >= arr[i].
    // Therefore the element left on top is STRICTLY smaller.
    //
    // If stack is empty -> no smaller element on right
    // So use n as boundary.
    //
    // IMPORTANT:
    // NSE -> pop >=
    // --------------------------------------------------------

    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {

        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        nse[i] = st.empty() ? n : st.top();

        st.push(i);
    }


    // Clear stack before finding PSEE
    while (!st.empty()) {
        st.pop();
    }


    // --------------------------------------------------------
    // STEP 2: Find PSEE
    // --------------------------------------------------------
    // Traverse from LEFT -> RIGHT.
    //
    // Pop elements which are STRICTLY greater than arr[i].
    // Equal elements are NOT popped.
    //
    // Therefore the element left on top is:
    // Previous Smaller OR Equal.
    //
    // If stack is empty -> no PSEE
    // So use -1 as boundary.
    //
    // IMPORTANT:
    // PSEE -> pop >
    // --------------------------------------------------------

    for (int i = 0; i < n; i++) {

        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }

        psee[i] = st.empty() ? -1 : st.top();

        st.push(i);
    }


    // --------------------------------------------------------
    // STEP 3: Calculate contribution of every element
    // --------------------------------------------------------

    long long total = 0;

    for (int i = 0; i < n; i++) {

        // Number of choices for left boundary
        long long left = i - psee[i];

        // Number of choices for right boundary
        long long right = nse[i] - i;

        // Number of subarrays where arr[i] is minimum
        long long contribution =
            (left * right) % MOD * arr[i] % MOD;

        total = (total + contribution) % MOD;
    }

    return total;
}


// ============================================================
// QUICK REVISION
// ============================================================
//
// BRUTE FORCE:
// For every subarray -> find minimum
// TC = O(N^2)
// SC = O(1)
//
// STACK:
// For every element -> count subarrays where it is minimum
//
// PSEE = Previous Smaller OR Equal
// NSE  = Next Smaller
//
// PSEE -> pop >
// NSE  -> pop >=
//
// No PSEE -> -1
// No NSE  -> n
//
// left  = i - PSEE[i]
// right = NSE[i] - i
//
// contribution = left * right * arr[i]
//
// TC = O(N)
// SC = O(N)
//
// WHY DIFFERENT > and >= ?
// To handle DUPLICATES without double-counting.
// One side keeps equal elements, the other side removes them.
//
// ============================================================


// FINAL CODE:

#include <bits/stdc++.h>
using namespace std;

// Sum of Subarray Minimums
int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    const long long MOD = 1e9 + 7;

    vector<int> nse(n), psee(n);

    // Find Next Smaller Element
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        nse[i] = st.empty() ? n : st.top();

        st.push(i);
    }

    // Clear stack
    while (!st.empty()) {
        st.pop();
    }

    // Find Previous Smaller or Equal Element
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }

        psee[i] = st.empty() ? -1 : st.top();

        st.push(i);
    }

    // Calculate contribution of every element
    long long total = 0;

    for (int i = 0; i < n; i++) {
        long long left = i - psee[i];
        long long right = nse[i] - i;

        total = (total + (left * right % MOD) * arr[i]) % MOD;
    }

    return total;
}

int main() {
    vector<int> arr = {3, 1, 2, 4};

    cout << sumSubarrayMins(arr) << endl;

    return 0;
}

// PSEE -> Previous Smaller OR Equal -> pop >
// NSE  -> Next Smaller            -> pop >=
//
// left  = i - psee[i];
// right = nse[i] - i;
//
// contribution = left * right * arr[i];
