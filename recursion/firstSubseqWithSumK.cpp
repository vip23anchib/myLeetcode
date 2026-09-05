#include <bits/stdc++.h>
using namespace std;

bool printS(
    int ind,
    vector<int>& ds,
    int s,
    int sum,
    int arr[],
    int n
) {

    // BASE CASE
    // We have considered all elements
    if(ind == n) {

        // Found a subsequence with target sum
        if(s == sum) {

            // Print the subsequence
            for(auto it : ds)
                cout << it << " ";

            cout << endl;

            // Tell the caller that we found an answer
            return true;
        }

        // No valid subsequence on this path
        return false;
    }


    // -------------------------
    // PICK
    // -------------------------

    ds.push_back(arr[ind]);
    s += arr[ind];

    // If this branch finds an answer,
    // immediately stop the entire recursion.
    if(printS(ind + 1, ds, s, sum, arr, n))
        return true;


    // -------------------------
    // BACKTRACK
    // -------------------------

    // Undo the PICK
    s -= arr[ind];
    ds.pop_back();


    // -------------------------
    // NOT PICK
    // -------------------------

    // Try without taking arr[ind]
    if(printS(ind + 1, ds, s, sum, arr, n))
        return true;


    // Neither PICK nor NOT PICK found an answer
    return false;
}


int main() {

    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;

    vector<int> ds;

    printS(0, ds, 0, sum, arr, n);

    return 0;
}
