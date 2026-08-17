/*
============================================================
        KTH LARGEST DISTINCT ELEMENT - USING SORT
============================================================

Problem:

Given an array of N integers and an integer K, find the
K-th largest DISTINCT element.

Duplicates should be counted only once.

Example:

Input:
5
4 3 2 3 1
2

Distinct elements:
4 3 2 1

2nd largest = 3

Output:
3

------------------------------------------------------------

Input Format:

First line:
N

Second line:
N integers

Third line:
K

------------------------------------------------------------

Output:

Print the K-th largest distinct element.

If there are fewer than K distinct elements, print -1.

============================================================
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // Read the size of the array.
    int n;
    cin >> n;

    // Create the array.
    int arr[n];

    // Read all array elements.
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Read K.
    int k;
    cin >> k;

    // Sort the array in descending order.
    sort(arr, arr + n, greater<int>());

    // Count distinct elements.
    int count = 0;

    // Store the previous element to detect duplicates.
    int previous = 0;

    // Traverse the sorted array.
    for (int i = 0; i < n; i++)
    {
        // If this is the first element OR different from previous,
        // then it is a new distinct element.
        if (i == 0 || arr[i] != previous)
        {
            // Increase the distinct element count.
            count++;

            // Store the current element.
            previous = arr[i];

            // If we reached K-th largest distinct element,
            // print it and stop.
            if (count == k)
            {
                cout << arr[i];
                return 0;
            }
        }
    }

    // If there were fewer than K distinct elements.
    cout << -1;

    return 0;
}


/*
============================================================
        KTH LARGEST DISTINCT ELEMENT - WITHOUT SORT
============================================================

Problem:

Given an array of N integers and K, find the K-th largest
DISTINCT element.

We are NOT allowed to use sorting.

Duplicates must be ignored.

Example:

Input:
5
4 3 2 3 1
2

Distinct elements in descending order:

4 3 2 1

Therefore:

2nd largest = 3

Output:
3

------------------------------------------------------------

Approach:

1. Find the largest element.
2. For every next position, find the largest element that
   is STRICTLY smaller than the previous largest element.
3. Repeat K times.

Because we require:

    arr[i] < previous

duplicate values are automatically ignored.

Example:

Array:
4 3 2 3 1

First largest:
4

Next largest smaller than 4:
3

Next largest smaller than 3:
2

Next largest smaller than 2:
1

============================================================
*/

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    // Read the size of the array.
    int n;
    cin >> n;

    // Create the array.
    int arr[n];

    // Read all array elements.
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Read K.
    int k;
    cin >> k;

    // previous stores the largest element found in the
    // previous iteration.
    int previous = INT_MAX;

    // Repeat the process K times.
    for (int count = 1; count <= k; count++)
    {
        // candidate stores the largest valid element
        // found in the current iteration.
        int candidate = INT_MIN;

        // Traverse the entire array.
        for (int i = 0; i < n; i++)
        {
            // We need a number smaller than the previous
            // selected number.
            if (arr[i] < previous)
            {
                // Keep the largest such number.
                if (arr[i] > candidate)
                {
                    candidate = arr[i];
                }
            }
        }

        // If no candidate was found, there are fewer
        // than K distinct elements.
        if (candidate == INT_MIN)
        {
            cout << -1;
            return 0;
        }

        // The candidate becomes the previous value
        // for the next iteration.
        previous = candidate;
    }

    // After K iterations, previous contains the
    // K-th largest distinct element.
    cout << previous;

    return 0;
}
