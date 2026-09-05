#include <bits/stdc++.h>
using namespace std;

int countSubseq(int ind, int s, int sum, int arr[], int n) {

    // Base case:
    // We have considered all elements
    if(ind == n) {

        // If the current subsequence has sum = target,
        // we found ONE valid subsequence
        if(s == sum)
            return 1;

        // This branch does not give a valid subsequence
        return 0;
    }

    // ---------------- PICK ----------------
    // Pick arr[ind]
    s += arr[ind];

    int left = countSubseq(ind + 1, s, sum, arr, n);


    // ---------------- BACKTRACK ----------------
    // Undo the pick
    s -= arr[ind];


    // ---------------- NOT PICK ----------------
    // Don't pick arr[ind]
    int right = countSubseq(ind + 1, s, sum, arr, n);


    // Total number of valid subsequences
    // = valid subsequences from PICK
    // + valid subsequences from NOT PICK
    return left + right;
}


int main() {

    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;

    int count = countSubseq(0, 0, sum, arr, n);

    cout << "Number of subsequences with sum " << sum
         << " = " << count << endl;

    return 0;
}
