// APPROACH 1: Brute Force
// For each element:
// 1. Search to its right for the first greater element.
// 2. If not found, search from the beginning up to i-1 (circular part).
// 3. If still not found, answer = -1.
// Time: O(n^2), Space: O(n) for answer.

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++) {

            bool found = false;

            // First search normally to the right
            for(int j = i + 1; j < n; j++) {

                if(nums[j] > nums[i]) {
                    ans.push_back(nums[j]);
                    found = true;
                    break;
                }
            }

            // If not found, search circularly from the beginning
            if(found == false) {

                for(int j = 0; j < i; j++) {

                    if(nums[j] > nums[i]) {
                        ans.push_back(nums[j]);
                        found = true;
                        break;
                    }
                }

                // No greater element anywhere
                if(found == false) {
                    ans.push_back(-1);
                }
            }
        }

        return ans;
    }
};

//--------------------------------------------------------------------------------------------------
// APPROACH 2: Virtual Doubling using j % n
// Treat the circular array as if it were [nums + nums]
// without actually creating a second array.
// For each i, search the next n-1 positions.
// j % n converts the virtual index back into the original array.
// Time: O(n^2), Space: O(n) for answer.

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {

            bool found = false;

            // Search next n-1 elements, including circular part
            for(int j = i + 1; j < i + n; j++) {

                int ind = j % n;

                if(nums[ind] > nums[i]) {
                    ans.push_back(nums[ind]);
                    found = true;
                    break;
                }
            }

            // No greater element found
            if(found == false) {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};

// Circular array → imagine doubling it
//               → use j % n


//---------------------------------------------------------------------------// APPROACH 3: Monotonic Stack
// Traverse from right to left over 2*n elements
// to simulate the circular array.
// Maintain a decreasing stack of possible greater elements.
// Remove all elements <= current because they can never be the answer.
// Stack top = next greater element.
// Time: O(n), Space: O(n).

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n);

        stack<int> st;

        // Traverse twice to handle circular nature
        for(int i = 2 * n - 1; i >= 0; i--) {

            // Remove elements that cannot be next greater
            while(!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }

            // Fill answer only during the first/original pass
            if(i < n) {
                ans[i] = st.empty() ? -1 : st.top();
            }

            // Current element becomes a candidate for future elements
            st.push(nums[i % n]);
        }

        return ans;
    }
};
