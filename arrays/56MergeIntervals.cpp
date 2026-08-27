// Q: Given intervals [start, end], merge all overlapping intervals.
//
// Example:
// [1,3], [2,6], [8,10], [15,18]
// → [1,6], [8,10], [15,18]
//
// APPROACH:
// 1. Sort intervals by starting point.
// 2. Keep one interval as "current".
// 3. Compare current with the next interval.
// 4. If they overlap:
//      current[1] = max(current[1], next[1])
// 5. If they DON'T overlap:
//      current is complete → push it into ans
//      current = next interval
// 6. After the loop, push current.
//    This is IMPORTANT because the last interval has no next
//    interval to trigger its insertion.
//
// OVERLAP CONDITION:
//      intervals[i][0] <= current[1]
//
// If TRUE  → overlap → merge
// If FALSE → no overlap → push current
//
// TIME: O(n log n) because of sorting
// SPACE: O(n) for answer


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Sort intervals by their starting point
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        // First interval becomes our current interval
        vector<int> current = intervals[0];

        // Start from the second interval
        for(int i = 1; i < intervals.size(); i++) {

            // If current and next interval overlap
            if(intervals[i][0] <= current[1]) {

                // Merge them by taking the farther ending point
                current[1] = max(current[1], intervals[i][1]);
            }

            else {

                // No overlap
                // Current interval is finished
                ans.push_back(current);

                // Start a new current interval
                current = intervals[i];
            }
        }

        // Add the final current interval
        // There is no next interval to add it for us
        ans.push_back(current);

        return ans;
    }
};
