// Q: Given nums and k, check if there are two equal elements
//    whose indices are at most k apart.
//
// Brute Force Approach:
// - For every i, check every j after i.
// - If nums[i] == nums[j] and j - i <= k → duplicate found.
// - Otherwise continue.
//
// Time: O(n^2) → TLE for large inputs
// Space: O(1)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int n = nums.size();

        // Pick the first index
        for(int i = 0; i < n; i++) {

            // Check all elements after i
            for(int j = i + 1; j < n; j++) {

                // Since j keeps increasing, once
                // j - i > k, later j will also be > k
                if(j - i > k)
                    break;

                // Same value + index distance <= k
                if(nums[i] == nums[j])
                    return true;
            }
        }

        return false;
    }
};


// Q: Given nums and k, check if there are two equal elements
//    whose indices are at most k apart.
//
// Hash Map Approach:
// - Store: number → its latest index.
// - When we see the same number again:
//       current index - previous index <= k
//       → duplicate is nearby.
// - Always update the number's index to the latest position.
//
// Time: O(n) average
// Space: O(n)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        // Stores:
        // number → latest index where it was seen
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {

            // If this number was seen before
            if(mp.find(nums[i]) != mp.end()) {

                // Check distance between current index
                // and its previous/latest index
                if(i - mp[nums[i]] <= k)
                    return true;
            }

            // Store/update the latest index
            mp[nums[i]] = i;
        }

        return false;
    }
};
