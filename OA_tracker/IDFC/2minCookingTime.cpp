/*****************************************************************************************
                                    QUESTION
******************************************************************************************

At a restaurant, there are three types of chefs:

A -> Can cook only Dish A.
B -> Can cook only Dish B.
C -> Can cook both Dish A and Dish B.

Each chef has a cooking time.

Since only ONE chef can work in the kitchen at a time, the restaurant has two choices:

1. Hire one A chef and one B chef.
   Total Time = Time(A) + Time(B)

2. Hire one C chef.
   Total Time = Time(C)

Find the minimum time required to prepare both dishes.

*****************************************************************************************
                                    APPROACH
******************************************************************************************

Step 1:
Find the chef with the minimum time for type A.

Example:
A 7
A 2
A 5

Minimum A = 2

------------------------------------------------------------

Step 2:
Find the chef with the minimum time for type B.

Example:
B 9
B 3
B 4

Minimum B = 3

------------------------------------------------------------

Step 3:
Find the chef with the minimum time for type C.

Example:
C 8
C 5
C 10

Minimum C = 5

------------------------------------------------------------

Step 4:
If we hire separate chefs,

Time = minA + minB

------------------------------------------------------------

Step 5:
If we hire a chef who can cook both,

Time = minC

------------------------------------------------------------

Step 6:
Return the smaller of the two.

Answer = min(minA + minB, minC)

*****************************************************************************************
Time Complexity : O(N)
Space Complexity: O(1)
*****************************************************************************************/


#include <iostream>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;

    int minA = INT_MAX;
    int minB = INT_MAX;
    int minC = INT_MAX;

    for (int i = 0; i < N; i++) {
        char type;
        int t;
        cin >> type >> t;

        if (type == 'A')
            minA = min(minA, t);
        else if (type == 'B')
            minB = min(minB, t);
        else if (type == 'C')
            minC = min(minC, t);
    }

    int ans = INT_MAX;

    if (minA != INT_MAX && minB != INT_MAX)
        ans = minA + minB;

    if (minC != INT_MAX)
        ans = min(ans, minC);

    cout << ans;

    return 0;
}
