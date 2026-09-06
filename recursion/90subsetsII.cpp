class Solution {
public:

    // Stores all the unique subsets
    vector<vector<int>> ans;

    // Stores the subset currently being built
    vector<int> curr;


    void solve(vector<int>& nums, int index)
    {
        // Whatever is currently inside curr is a valid subset.
        // So add it to our answer.
        //
        // Example:
        // curr = {}
        // curr = {1}
        // curr = {1,2}
        // curr = {1,2,2}
        //
        // All of these are valid subsets.
        ans.push_back(curr);


        // Try choosing every element starting from 'index'
        for(int i = index; i < nums.size(); i++)
        {

            // IMPORTANT:
            //
            // If nums[i] is the same as the previous element,
            // and we are at the SAME recursion level,
            // skip it.
            //
            // This prevents duplicate subsets.
            //
            // Example:
            // nums = [1,2,2]
            //
            // At the same level:
            //        1
            //       / \
            //      2   2
            //
            // We don't need both branches.
            if(i > index && nums[i] == nums[i-1])
            {
                continue;
            }


            // Choose nums[i]
            curr.push_back(nums[i]);


            // Recursively find subsets using elements
            // AFTER i.
            //
            // i + 1 means we cannot reuse nums[i]
            // as the same element again.
            solve(nums, i + 1);


            // BACKTRACK
            //
            // Remove the element we just chose
            // so that we can try another choice.
            curr.pop_back();
        }
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        // Sort first!
        //
        // Example:
        // [4,4,4,1,4]
        //
        // becomes:
        // [1,4,4,4,4]
        //
        // Now duplicate values are next to each other,
        // so we can easily detect them using:
        // nums[i] == nums[i-1]
        sort(nums.begin(), nums.end());


        // Start recursion from index 0
        solve(nums, 0);


        // ans already contains only unique subsets
        return ans;
    }
};



// Sort first so duplicate elements are next to each other.
// This allows us to easily detect duplicates using nums[i] == nums[i-1].

// Add curr to ans at every recursion level because
// every curr represents a valid subset.

// Loop through all possible elements starting from index.

// Skip duplicate elements ONLY at the same recursion level.
// i > index means we are not choosing the first element of this level.
// nums[i] == nums[i-1] means the same value was already considered.
// This prevents generating duplicate subsets.

// Choose the current element and add it to curr.

// Recursively generate subsets using elements after i.
// i + 1 ensures we don't reuse the same array element.

// Backtrack: remove the chosen element
// so we can try the next possibility.

// Same values are allowed at DIFFERENT recursion levels.
// Example: [2,2] is valid.

// Key idea:
// SORT → SKIP DUPLICATES AT SAME LEVEL → ALLOW DUPLICATES AT DEEPER LEVEL
