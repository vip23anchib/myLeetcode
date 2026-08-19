// APPROACH 1: Brute Force
// For every element, search from left to right's immediate side
// starting from i-1 and move backwards.
// The first smaller element found is the previous smaller element.
// If none is found, answer = -1.
// Time: O(n^2)
// Space: O(n) for answer

class Solution {
public:
    vector<int> previousSmallerElement(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++) {

            bool found = false;

            // Search backwards from the immediate previous element
            for(int j = i - 1; j >= 0; j--) {

                if(nums[j] < nums[i]) {
                    ans.push_back(nums[j]);
                    found = true;
                    break;
                }
            }

            // No smaller element found on the left
            if(found == false) {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};

// APPROACH 2: Monotonic Increasing Stack
// Traverse from left to right.
// Remove elements from the stack while they are >= current element,
// because they cannot be the previous smaller element.
// After popping:
//     stack.top() = previous smaller element
// If stack is empty, answer = -1.
// Then push the current element.
// Time: O(n) because every element is pushed and popped at most once.
// Space: O(n)

class Solution {
public:
    vector<int> previousSmallerElement(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n);

        stack<int> st;

        for(int i = 0; i < n; i++) {

            // Remove elements that are not smaller
            while(!st.empty() && st.top() >= nums[i]) {
                st.pop();
            }

            // Top is the nearest smaller element
            if(st.empty()) {
                ans[i] = -1;
            }
            else {
                ans[i] = st.top();
            }

            // Current element becomes a candidate for future elements
            st.push(nums[i]);
        }

        return ans;
    }
};
