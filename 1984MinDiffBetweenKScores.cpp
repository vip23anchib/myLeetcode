class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;

        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;

        for (int i = 0; i + k - 1 < nums.size(); i++) {
            minDiff = min(minDiff, nums[i + k - 1] - nums[i]);
        }

        return minDiff;
    }
};
/*
You must:

choose any k students

compute:
highest score − lowest score

return the minimum possible difference

CRITICAL: After sorting the array:

The best group of k students will always be k consecutive elements

Why?

If you skip elements, the range only gets bigger

Consecutive elements minimize max − min
*/