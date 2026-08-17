/*
============================================================
          FILE SYSTEM INDEX TRACKER (FAT SIMULATION)
============================================================

PROBLEM STATEMENT
-----------------

A File Allocation Table (FAT) is used to keep track of how
different blocks/clusters of a file are connected.

The FAT is represented as a predefined array.

For this problem:

    FAT = [-2, 2, 4, -1, 7, -1, -1, 6]

Each index represents a block, and the value stored at that
index tells us where to go next.

Meaning of special values:

    -2  -> Reserved block (invalid)
    -1  -> EOF (End Of File), meaning STOP

For a normal positive value:

    FAT[current] = next index

So if:

    FAT[1] = 2

it means:

    Start at index 1
          ↓
    Go to index 2

Then if:

    FAT[2] = 4

we go:

    2 → 4

Therefore, the array behaves like a linked list:

    index 1 → index 2 → index 4 → index 7 → index 6 → EOF


INPUT
-----

The input contains ONE integer:

    start

This is the starting index from which we have to begin
traversing the FAT.

IMPORTANT:
The FAT array is ALREADY GIVEN in the problem.
We do NOT take the array as input.


OUTPUT
------

Print all indices visited during the traversal, starting
from 'start' and stopping when EOF (-1) is reached.

If the starting index is invalid, reserved, out of bounds,
or the traversal enters a cycle, print:

    Invalid


EXAMPLE
-------

FAT:

index:   0   1   2   3   4   5   6   7
value:  -2   2   4  -1   7  -1  -1   6


Input:

    1

Traversal:

    1
    ↓
    FAT[1] = 2

    2
    ↓
    FAT[2] = 4

    4
    ↓
    FAT[4] = 7

    7
    ↓
    FAT[7] = 6

    6
    ↓
    FAT[6] = -1

    STOP


Output:

    1 2 4 7 6


IMPORTANT IDEA
--------------

The most important line in the entire problem is:

    next = FAT[current];

The VALUE stored at the current index tells us which
index to visit next.

This is basically an array-based linked list traversal.


EDGE CASES
----------

1. start < 0
       → Invalid

2. start >= size of FAT
       → Invalid

3. FAT[start] == -2
       → Starting block is reserved
       → Invalid

4. FAT[current] == -1
       → EOF reached
       → STOP normally

5. Next index is outside the FAT array
       → Invalid

6. A previously visited index is encountered again
       → Cycle detected
       → Invalid


============================================================
                       C++ SOLUTION
============================================================
*/

#include <iostream>
using namespace std;

int main()
{
    /*
    --------------------------------------------------------
    STEP 1: Store the predefined FAT array
    --------------------------------------------------------
    This array is given in the problem statement.
    We DO NOT take this array as input.
    Index:   0   1   2   3   4   5   6   7
    FAT:    -2   2   4  -1   7  -1  -1   6
    For example:
        FAT[1] = 2

    means from index 1, go to index 2.
        FAT[2] = 4
    means from index 2, go to index 4.
    --------------------------------------------------------
    */

    int FAT[8] = {-2, 2, 4, -1, 7, -1, -1, 6};


    /*
    --------------------------------------------------------
    STEP 2: Take the starting index as input
    --------------------------------------------------------
    The input contains only ONE integer.
    Example:
        Input:
        1
    means:
        start = 1
    --------------------------------------------------------
    */

    int start;
    cin >> start;

    /*
    --------------------------------------------------------
    STEP 3: Check whether the starting index is valid
    --------------------------------------------------------
    Valid indices of FAT are:

        0, 1, 2, 3, 4, 5, 6, 7
    Therefore:
        start < 0
        OR
        start >= 8
    means the starting index is outside the array.
    --------------------------------------------------------
    */

    if (start < 0 || start >= 8)
    {
        cout << "Invalid";
        return 0;
    }

    /*
    --------------------------------------------------------
    STEP 4: Check whether the starting block is reserved
    --------------------------------------------------------

    -2 means RESERVED.
    Therefore, if:
        FAT[start] == -2
    the starting block cannot be used.
    --------------------------------------------------------
    */

    if (FAT[start] == -2)
    {
        cout << "Invalid";
        return 0;
    }


    /*
    --------------------------------------------------------
    STEP 5: Create a visited array for cycle detection
    --------------------------------------------------------

    Initially, none of the indices have been visited.
        visited[0] = false
        visited[1] = false
        ...
        visited[7] = false
    If we visit an index, we change it to true.

    This helps us detect a cycle.
    Example of a cycle:

        1 → 2 → 4 → 7 → 6 → 1 → 2 → ...
    Without visited[], the while loop would run forever.
    --------------------------------------------------------
    */

    bool visited[8] = {false};

    /*
    --------------------------------------------------------
    STEP 6: Start traversal from the given index
    --------------------------------------------------------
    If:
        start = 1
    then:
        current = 1
    --------------------------------------------------------
    */

    int current = start;
    /*
    --------------------------------------------------------
    STEP 7: Keep traversing
    --------------------------------------------------------

    We don't know beforehand how many times we need to move.
    So we use a while loop.
    We will stop when:
        FAT[current] == -1
    because -1 means EOF.
    --------------------------------------------------------
    */

    while (true)
    {

        /*
        ----------------------------------------------------
        STEP 7A: Check for a cycle
        ----------------------------------------------------
        If we have already visited 'current', then we have
        come back to an index we saw before.
        That means there is a cycle.
        Example:

            1 → 2 → 4 → 7 → 6 → 1

        When current becomes 1 again:
            visited[1] == true
        Therefore the traversal is invalid.
        ----------------------------------------------------
        */

        if (visited[current])
        {
            cout << "Invalid";
            return 0;
        }


        /*
        ----------------------------------------------------
        STEP 7B: Mark the current index as visited
        ----------------------------------------------------
        */

        visited[current] = true;


        /*
        ----------------------------------------------------
        STEP 7C: Print the current index
        ----------------------------------------------------

        For example:
            current = 1
        We print:

            1
        ----------------------------------------------------
        */

        cout << current;


        /*
        ----------------------------------------------------
        STEP 7D: Check whether we have reached EOF
        ----------------------------------------------------

        If:

            FAT[current] == -1
        then there is no next block.
        Therefore, traversal is complete.

        Example:
            current = 6
            FAT[6] = -1
        So we stop.
        ----------------------------------------------------
        */

        if (FAT[current] == -1)
        {
            break;
        }


        /*
        ----------------------------------------------------
        STEP 7E: Find the next index
        ----------------------------------------------------

        THIS IS THE MOST IMPORTANT LINE.

            next = FAT[current]

        The value stored at the current index tells us
        where to go next.

        Example:

            current = 1

            FAT[1] = 2

            next = 2


        Then:

            current = 2

        and repeat the same process.
        ----------------------------------------------------
        */

        int next = FAT[current];


        /*
        ----------------------------------------------------
        STEP 7F: Check whether the next index is valid
        ----------------------------------------------------

        A normal FAT value should point to a valid index.

        Valid indices are:

            0 to 7

        If next is negative (except -1, which was already
        handled above) or greater than/equal to 8, it is
        invalid.
        ----------------------------------------------------
        */

        if (next < 0 || next >= 8)
        {
            cout << "\nInvalid";
            return 0;
        }


        /*
        ----------------------------------------------------
        STEP 7G: Print a space before the next index
        ----------------------------------------------------
        */

        cout << " ";


        /*
        ----------------------------------------------------
        STEP 7H: Move to the next index
        ----------------------------------------------------

        Example:

            current = 1
            FAT[1] = 2

        Therefore:

            current = 2

        Then the loop starts again.
        ----------------------------------------------------
        */

        current = next;
    }


    /*
    --------------------------------------------------------
    Program finished successfully.
    --------------------------------------------------------
    */

    return 0;
}


/*
============================================================
                     DRY RUN
============================================================

Suppose input is:

    1


Initial:

    current = 1


ITERATION 1
-----------

current = 1

visited[1] = false
→ mark visited[1] = true

print 1

FAT[1] = 2

2 is not EOF.

current = 2


ITERATION 2
-----------

current = 2

visited[2] = false
→ mark visited[2] = true

print 2

FAT[2] = 4

4 is not EOF.

current = 4


ITERATION 3
-----------

current = 4

visited[4] = false
→ mark visited[4] = true

print 4

FAT[4] = 7

current = 7


ITERATION 4
-----------

current = 7

visited[7] = false
→ mark visited[7] = true

print 7

FAT[7] = 6

current = 6


ITERATION 5
-----------

current = 6

visited[6] = false
→ mark visited[6] = true

print 6

FAT[6] = -1

-1 means EOF.

STOP.


FINAL OUTPUT:

    1 2 4 7 6


============================================================
                     CORE LOGIC TO REMEMBER
============================================================

Forget all the FAT terminology.

Think only:

    current
       ↓
    FAT[current]
       ↓
    next index
       ↓
    current = next


For example:

    current = 1
    FAT[1] = 2

    current = 2
    FAT[2] = 4

    current = 4
    FAT[4] = 7

    current = 7
    FAT[7] = 6

    current = 6
    FAT[6] = -1

    STOP


In one sentence:

    "The value at the current index tells me
     which index I should visit next."

============================================================
*/



//SO OVERALL:
// I am given a fixed array and one starting index. The value at the current index gives me the next index.
//I keep jumping current → FAT[current] until I reach -1.

#include <iostream>
using namespace std;

int main() {

    // Given in the problem statement
    int FAT[8] = {-2, 2, 4, -1, 7, -1, -1, 6};

    // Input
    int start;
    cin >> start;

    // Check if starting index is invalid
    if (start < 0 || start >= 8) {
        cout << "Invalid";
        return 0;
    }

    // Starting block cannot be reserved
    if (FAT[start] == -2) {
        cout << "Invalid";
        return 0;
    }

    // To detect cycles
    bool visited[8] = {false};

    int current = start;

    while (true) {

        // Cycle detected
        if (visited[current]) {
            cout << "Invalid";
            return 0;
        }

        visited[current] = true;

        // Print current index
        cout << current;

        // If current points to EOF, stop
        if (FAT[current] == -1) {
            break;
        }

        // Get next index
        int next = FAT[current];

        // Next index must be valid
        if (next < 0 || next >= 8) {
            cout << "\nInvalid";
            return 0;
        }

        cout << " ";

        current = next;
    }

    return 0;
}
