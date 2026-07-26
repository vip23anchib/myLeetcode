/*
=========================================
LEETCODE 875 - KOKO EATING BANANAS
BRUTE FORCE APPROACH
=========================================

IDEA:
------
Try every possible eating speed starting from 1 banana/hour.
For each speed, calculate the total hours required to finish all piles.
The first speed that allows Koko to finish within 'h' hours is the answer.

STEPS:
------
1. Find the largest pile.
   -> Maximum possible speed = largest pile
      (No need to eat faster than the biggest pile.)

2. For every speed from 1 to maxPile:
      a) Calculate total hours required.
      b) Hours for one pile =
            ceil(pile / speed)
         Instead of using:
            ceil((double)pile / speed)

         Use integer ceiling division:
            (pile + speed - 1) / speed

      c) Add hours of every pile.

3. If totalHours <= h,
      return current speed
      because we are checking speeds from smallest to largest,
      so this is the minimum valid speed.

WHY long long?
--------------
When speed = 1,
totalHours = sum of all piles.

This sum can exceed the int limit (2,147,483,647),
so use long long to avoid overflow.

TIME COMPLEXITY:
----------------
Finding max pile : O(n)

Trying every speed:
    maxPile possibilities

For each speed:
    Traverse all piles -> O(n)

Overall:
    O(n * maxPile)

SPACE COMPLEXITY:
-----------------
O(1)

NOTE:
-----
This brute-force approach is too slow for large inputs
(TLE on LeetCode).

The optimized solution uses Binary Search because:
- As speed increases, required hours decrease.
- This monotonic behaviour allows binary search.
- Time complexity becomes O(n * log(maxPile)).
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        // Maximum possible speed = largest pile
        int maxPile = *max_element(piles.begin(), piles.end());

        // Try every possible speed from 1 to maxPile
        for (int speed = 1; speed <= maxPile; speed++) {

            long long totalHours = 0;

            // Calculate hours needed at this speed
            for (int pile : piles) {

                // Ceiling division:
                // ceil((double)pile / speed)
                // implemented using integer arithmetic
                totalHours += (pile + speed - 1) / speed;
              //OR
              //totalHours += ceil((double)pile / speed);
            }

            // If Koko can finish within h hours,
            // this is the minimum valid speed.
            if (totalHours <= h) {
                return speed;
            }
        }

        // This line is never practically reached because
        // speed = maxPile will always work.
        return maxPile;
    }
};

/*
==========================================================
BINARY SEARCH APPROACH
==========================================================

OBSERVATION:
------------
As eating speed increases,
the total hours required decreases.

Speed : 1   2   3   4   5 ...
Hours : 20 12  9   7   6 ...

This is a monotonic (sorted) relationship,
so Binary Search can be applied on the answer.

----------------------------------------------------------
HOW TO THINK
----------------------------------------------------------

We are NOT searching in the array.

We are searching for the MINIMUM eating speed
that allows Koko to finish within h hours.

Search Space:
-------------
Minimum possible speed = 1 banana/hour

Maximum possible speed = largest pile
(because eating faster than the largest pile is unnecessary)

Therefore,

low = 1
high = max(piles)

----------------------------------------------------------
HELPER FUNCTION
----------------------------------------------------------

calculateHours(speed)

For a given eating speed,
calculate how many total hours Koko needs.

Hours for one pile:

ceil(pile / speed)

Instead of using floating point:
ceil((double)pile / speed)
Use integer ceiling division:
(pile + speed - 1) / speed

Example:
7 bananas, speed = 3

Hours = (7+3-1)/3
      = 9/3
      = 3
Add the hours for every pile.
---------------------------------------------------------
BINARY SEARCH
----------------------------------------------------------
mid = current eating speed

Case 1:
--------
If totalHours <= h

Current speed works.

Try to find an even smaller valid speed.

high = mid - 1

Case 2:
--------
If totalHours > h

Current speed is too slow.
Need to increase speed.
low = mid + 1;
Repeat until low > high.

Answer = low
----------------------------------------------------------
WHY RETURN LOW?
----------------------------------------------------------

Binary search ends when
low > high
At this point,
high = last invalid speed
low = first valid (minimum) speed
Hence,
return low.
---------------------------------------------------------
IMPORTANT POINTS
----------------------------------------------------------

1. Use long long for totalHours
   because sum of hours can exceed int range.

2. Compute mid safely:

   mid = low + (high - low) / 2

instead of

   (low + high) / 2

to avoid overflow.

3. Pass vector by reference:

   vector<int>& piles

to avoid copying the entire vector.

----------------------------------------------------------
TIME COMPLEXITY
----------------------------------------------------------

Finding max pile:
O(n)

Binary Search:
log(maxPile)

For every mid,
calculate hours by traversing all piles:
O(n)

Overall:

O(n * log(maxPile))
----------------------------------------------------------
PATTERN TO REMEMBER
----------------------------------------------------------

Whenever the question asks:

"Find the minimum/maximum value that satisfies a condition"

and

As answer increases/decreases,
the condition changes monotonically,

Think:

=> Binary Search on Answer.
*/
class Solution {
public:
    long long calculateHours(vector<int> piles, int mid){
            long long totalHrs=0;
            int n=piles.size();
            for(int i=0;i<n;i++){
                totalHrs+=ceil((double)piles[i]/mid);
            }
            return totalHrs;
        }

    int minEatingSpeed(vector<int>& piles, int h) {
        int max_speed=*max_element(piles.begin(),piles.end());
        int low=1;
        int high=max_speed;
        int ans=INT_MAX;

        while(low<=high){
            int mid=(low+high)/2;
            long long totalHrs=calculateHours(piles,mid);

            if(totalHrs<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }

    return low;
        
    }
};
