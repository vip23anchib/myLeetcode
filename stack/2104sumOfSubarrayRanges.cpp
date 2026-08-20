// BRUTE FORCE : O(N^2)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            int mini=INT_MAX;
            int maxi=INT_MIN;
            for(int j=i;j<n;j++){
                mini=min(mini,nums[j]);
                maxi=max(maxi,nums[j]);
                sum+=(maxi-mini);
            }
        }
    return sum; 
    }
};

//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
// OPTIMAL: USING STACKS
// ============================================================
// 2104. SUM OF SUBARRAY RANGES
// ============================================================
//
// Range of a subarray = MAXIMUM - MINIMUM
//
// Therefore:
//
// Sum of all subarray ranges
// = Sum of all subarray maximums
//   - Sum of all subarray minimums
//
// Instead of checking every subarray, we find the contribution
// of every element as a MINIMUM and as a MAXIMUM.
//
// ------------------------------------------------------------
// CONTRIBUTION IDEA
// ------------------------------------------------------------
//
// For every arr[i], find:
//
// How many choices do I have on the LEFT?
// How many choices do I have on the RIGHT?
//
// left  = i - previous_boundary
// right = next_boundary - i
//
// Number of subarrays where arr[i] is the min/max:
// = left * right
//
// Contribution:
// = arr[i] * left * right
//
// ------------------------------------------------------------
// WHY STACK?
// ------------------------------------------------------------
//
// We use a MONOTONIC STACK to find the nearest element that
// can stop arr[i] from being the minimum/maximum.
//
// The stack stores INDICES, not values.
//
// ------------------------------------------------------------
// FOR MINIMUM
// ------------------------------------------------------------
//
// PSEE = Previous Smaller OR Equal Element
// NSE  = Next Smaller Element
//
// PSEE:
// Traverse LEFT -> RIGHT.
// Pop elements that are STRICTLY GREATER.
//
//     while (arr[st.top()] > arr[i])
//
// Equal elements are NOT popped.
// Therefore the remaining element can be smaller OR equal.
//
// If stack is empty:
// PSEE = -1
//
// NSE:
// Traverse RIGHT -> LEFT.
// Pop elements that are GREATER THAN OR EQUAL.
//
//     while (arr[st.top()] >= arr[i])
//
// Therefore the remaining element is STRICTLY smaller.
//
// If stack is empty:
// NSE = n
//
// IMPORTANT:
// PSEE -> pop >
// NSE  -> pop >=
//
// The difference between > and >= is intentional.
// It handles DUPLICATE values without double-counting.
//
// ------------------------------------------------------------
// FOR MAXIMUM
// ------------------------------------------------------------
//
// PGEE = Previous Greater OR Equal Element
// NGE  = Next Greater Element
//
// This is the exact opposite of the minimum case.
//
// PGEE:
// Traverse LEFT -> RIGHT.
// Pop elements that are STRICTLY SMALLER.
//
//     while (arr[st.top()] < arr[i])
//
// Equal elements are NOT popped.
// Therefore the remaining element can be greater OR equal.
//
// If stack is empty:
// PGEE = -1
//
// NGE:
// Traverse RIGHT -> LEFT.
// Pop elements that are SMALLER THAN OR EQUAL.
//
//     while (arr[st.top()] <= arr[i])
//
// Therefore the remaining element is STRICTLY greater.
//
// If stack is empty:
// NGE = n
//
// IMPORTANT:
// PGEE -> pop <
// NGE  -> pop <=
//
// ------------------------------------------------------------
// CONTRIBUTION FOR MINIMUM
// ------------------------------------------------------------
//
// left  = i - PSEE[i]
// right = NSE[i] - i
//
// contribution = arr[i] * left * right
//
// Add contribution of every element.
//
// This gives:
// SUM OF ALL SUBARRAY MINIMUMS
//
// ------------------------------------------------------------
// CONTRIBUTION FOR MAXIMUM
// ------------------------------------------------------------
//
// left  = i - PGEE[i]
// right = NGE[i] - i
//
// contribution = arr[i] * left * right
//
// Add contribution of every element.
//
// This gives:
// SUM OF ALL SUBARRAY MAXIMUMS
//
// ------------------------------------------------------------
// FINAL ANSWER
// ------------------------------------------------------------
//
// answer
// = sumOfMaximums - sumOfMinimums
//
// ------------------------------------------------------------
// QUICK GLANCE
// ------------------------------------------------------------
//
//                 MINIMUM          MAXIMUM
//
// Previous:       PSEE             PGEE
// Previous pop:   >                <
//
// Next:           NSE              NGE
// Next pop:       >=               <=
//
// No previous:    -1               -1
// No next:        n                n
//
// Formula for both:
//
// left  = i - previous
// right = next - i
//
// contribution = arr[i] * left * right
//
// Final:
//
// answer = SUM(MAXIMUMS) - SUM(MINIMUMS)
//
// TC = O(N)
// SC = O(N)
//
// ============================================================/

class Solution {
public:

    // ---------------------------------------------------------
    // Find SUM OF SUBARRAY MINIMUMS
    // ---------------------------------------------------------
    long long sumOfMins(vector<int>& nums) {

        int n = nums.size();

        vector<int> nse(n);     // Next Smaller Element
        vector<int> psee(n);    // Previous Smaller OR Equal

        stack<int> st;


        // -----------------------------------------------------
        // STEP 1: Find NSE
        // -----------------------------------------------------
        // Traverse from RIGHT -> LEFT
        //
        // Pop elements >= nums[i]
        // So the element remaining on top is STRICTLY smaller.
        //
        // If stack is empty -> no smaller element on right
        // Therefore NSE = n
        //
        // NSE -> pop >=
        // -----------------------------------------------------

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }


        // Clear stack
        while (!st.empty()) {
            st.pop();
        }


        // -----------------------------------------------------
        // STEP 2: Find PSEE
        // -----------------------------------------------------
        // Traverse from LEFT -> RIGHT
        //
        // Pop elements > nums[i]
        // Equal elements are NOT popped.
        //
        // Therefore the remaining top is:
        // Previous Smaller OR Equal
        //
        // If stack is empty -> PSEE = -1
        //
        // PSEE -> pop >
        // -----------------------------------------------------

        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            psee[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }


        // -----------------------------------------------------
        // STEP 3: Calculate contribution of every element
        // -----------------------------------------------------

        long long total = 0;

        for (int i = 0; i < n; i++) {

            long long left = i - psee[i];
            long long right = nse[i] - i;

            total += (long long) nums[i] * left * right;
        }

        return total;
    }


    // ---------------------------------------------------------
    // Find SUM OF SUBARRAY MAXIMUMS
    // ---------------------------------------------------------
    long long sumOfMaxs(vector<int>& nums) {

        int n = nums.size();

        vector<int> nge(n);     // Next Greater Element
        vector<int> pgee(n);    // Previous Greater OR Equal

        stack<int> st;


        // -----------------------------------------------------
        // STEP 1: Find NGE
        // -----------------------------------------------------
        // Traverse from RIGHT -> LEFT
        //
        // Pop elements <= nums[i]
        // So the element remaining is STRICTLY greater.
        //
        // If stack is empty -> NGE = n
        //
        // NGE -> pop <=
        // -----------------------------------------------------

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            nge[i] = st.empty() ? n : st.top();

            st.push(i);
        }


        // Clear stack
        while (!st.empty()) {
            st.pop();
        }


        // -----------------------------------------------------
        // STEP 2: Find PGEE
        // -----------------------------------------------------
        // Traverse from LEFT -> RIGHT
        //
        // Pop elements < nums[i]
        // Equal elements are NOT popped.
        //
        // Therefore remaining top is:
        // Previous Greater OR Equal
        //
        // If stack is empty -> PGEE = -1
        //
        // PGEE -> pop <
        // -----------------------------------------------------

        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            pgee[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }


        // -----------------------------------------------------
        // STEP 3: Calculate contribution of every element
        // -----------------------------------------------------

        long long total = 0;

        for (int i = 0; i < n; i++) {

            long long left = i - pgee[i];
            long long right = nge[i] - i;

            total += (long long) nums[i] * left * right;
        }

        return total;
    }


    // ---------------------------------------------------------
    // FINAL ANSWER
    // ---------------------------------------------------------

    long long subArrayRanges(vector<int>& nums) {

        long long maximumSum = sumOfMaxs(nums);
        long long minimumSum = sumOfMins(nums);

        return maximumSum - minimumSum;
    }
};
