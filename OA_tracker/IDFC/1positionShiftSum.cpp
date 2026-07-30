/*
===========================================================
        POSITION SHIFT SUM AFTER SORTING
===========================================================

Problem:
--------
Given an array of N integers, sort the array in ascending order.

For every element:
Contribution = Element × Number of positions shifted

Return the sum of all contributions.

-----------------------------------------------------------
METHOD 1 : UNIQUE ELEMENTS
-----------------------------------------------------------

Idea:
-----
1. Create a copy of the original array.
2. Sort the copied array.
3. Traverse the sorted array.
4. For every element:
      • Find its original index in the original array.
      • Calculate the shift.
      • Add (element × shift) to the answer.

Since every element is unique,
searching by value always returns the correct index.

Time Complexity:
----------------
Copy Array      : O(N)
Sort            : O(N log N)
Search Index    : O(N²)

Overall         : O(N²)

Space Complexity:
-----------------
O(N)

===========================================================
CODE
===========================================================
*/

#include <iostream>
#include <algorithm>
using namespace std;

long printResults(int *A, int N)
{
    long res = 0;

    int copy[N];

    for (int i = 0; i < N; i++)
        copy[i] = A[i];

    sort(copy, copy + N);

    for (int i = 0; i < N; i++)
    {
        int originalIndex = -1;

        for (int j = 0; j < N; j++)
        {
            if (A[j] == copy[i])
            {
                originalIndex = j;
                break;
            }
        }

        int shift = abs(i - originalIndex);

        res += (long)copy[i] * shift;
    }

    return res;
}

int main()
{
    int N;
    cin >> N;

    int arr[N];

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cout << printResults(arr, N);

    return 0;
}

/*
===========================================================
        POSITION SHIFT SUM AFTER SORTING
        (ARRAY WITH DUPLICATE ELEMENTS)
===========================================================

Problem with Previous Method:
-----------------------------

Example:

Original :
5 3 5 1

Sorted :
1 3 5 5

Searching for value 5 always returns
the first occurrence.

So we cannot determine which duplicate
actually moved to which position.

Hence the previous approach fails.

-----------------------------------------------------------
METHOD 2 : DUPLICATE ELEMENTS
-----------------------------------------------------------

Idea:
-----

Instead of storing only values,

Store:

(value, originalIndex)

Example:

(5,0)
(3,1)
(5,2)
(1,3)

Now every duplicate remembers
its own original position.

Sort these pairs according to value.

After sorting:

(1,3)
(3,1)
(5,0)
(5,2)

Now,

Current Index = i

Original Index = arr[i].second

Shift = abs(CurrentIndex - OriginalIndex)

Contribution = Value × Shift

No searching is required.

Time Complexity:
----------------

Create Pairs : O(N)

Sorting      : O(N log N)

Traversal    : O(N)

Overall      : O(N log N)

Space Complexity:
-----------------
O(N)

Note:
-----
Use stable_sort() if the relative order
of duplicate elements must remain unchanged.

===========================================================
CODE
===========================================================
*/

#include <iostream>
#include <algorithm>
using namespace std;

long printResults(int *A, int N)
{
    long res = 0;

    pair<int, int> arr[N];

    for (int i = 0; i < N; i++)
    {
        arr[i].first = A[i];
        arr[i].second = i;
    }

    stable_sort(arr, arr + N);

    for (int i = 0; i < N; i++)
    {
        int shift = abs(i - arr[i].second);

        res += (long)arr[i].first * shift;
    }

    return res;
}

int main()
{
    int N;
    cin >> N;

    int arr[N];

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cout << printResults(arr, N);

    return 0;
}
