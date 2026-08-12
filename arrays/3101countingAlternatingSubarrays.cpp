/* 
  PATTERN:
Count valid subarrays by considering their ENDING index.

current =
number of valid alternating subarrays ending at i
=
length of current alternating streak.

If nums[i] != nums[i-1]:
        current++

Else:
        current = 1

answer += current

Why?
If current = k, then there are exactly k valid
alternating subarrays ending at i.
------------------------------------------------------------
The key observation ⭐
Instead of asking:
"How many alternating subarrays are there?"
ask:
"How many alternating subarrays end at index i?"

Suppose:

nums = [0, 1, 0]

At index 2:

        [0]        ← valid
      [1,0]        ← valid
    [0,1,0]        ← valid

So there are 3 alternating subarrays ending at index 2.

Therefore:

number of valid subarrays ending at i
    = length of the current alternating streak

This is the entire trick.
--------------------------------------------------------------
Example:
[0,1,0]

At i = 2:
[0]
[1,0]
[0,1,0]

=> current = 3
=> add 3 to answer.

TIME:  O(n)
SPACE: O(1)

IMPORTANT:
Use long long because the number of subarrays can be
O(n²).
*/

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {

        // Total number of alternating subarrays
        long long count = 1;

        // Number of alternating subarrays
        // ending at the current index
        long long current = 1;

        for (int i = 1; i < nums.size(); i++) {

            // If adjacent elements are different,
            // the alternating streak continues
            if (nums[i] != nums[i - 1]) {
                current++;
            }

            // If adjacent elements are same,
            // only the single element subarray is valid
            else {
                current = 1;
            }

            // Add all valid subarrays ending at i
            count += current;
        }

        return count;
    }
};
