// 5. Longest Palindromic Substring
//
// IDEA:
// Every palindrome has a CENTER.
// Try every index as a center and expand outward.
//----------------------------------------------------------------------------------------------------
// For EVERY i, the code checks both possibilities:

// Is there an odd-length palindrome centered at i?
// Is there an even-length palindrome centered between i and i+1?
//-----------------------------------------------------------------------------------------------------
// It doesn't know beforehand whether the answer is odd or even. That's precisely why we check both.
// There are 2 types:
//
// 1. ODD length → one center
//    "aba"
//      ↑
//    left = i
//    right = i
//
// 2. EVEN length → center between 2 chars
//    "abba"
//      ↑↑
//    left = i
//    right = i + 1
//
// At each center:
// - Expand while:
//      left >= 0
//      right < n
//      s[left] == s[right]
//
// - Current length:
//      right - left + 1
//
// - If longer than maxLen:
//      maxLen = length
//      start = left
//
// - Expand:
//      left--
//      right++
//
// At end:
//      s.substr(start, maxLen)
//
// IMPORTANT:
// Don't forget BOTH odd and even cases.
//
// Time: O(n²)
// Space: O(1)


class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();

        // Remember the best palindrome found so far
        int start = 0;
        int maxLen = 1;

        // Try every index as a possible center
        for(int i = 0; i < n; i++) {

            // =========================
            // 1. ODD-LENGTH PALINDROME
            // =========================
            // Example: "aba"
            //          ↑
            //       one center
            int left = i;
            int right = i;

            // Expand outward while characters match
            while(left >= 0 && right < n &&
                  s[left] == s[right]) {

                int len = right - left + 1;

                // Found a longer palindrome
                if(len > maxLen) {
                    maxLen = len;
                    start = left;
                }

                // Expand outward
                left--;
                right++;
            }


            // ==========================
            // 2. EVEN-LENGTH PALINDROME
            // ==========================
            // Example: "abba"
            //          ↑↑
            //      center is between them
            left = i;
            right = i + 1;

            // Expand outward
            while(left >= 0 && right < n &&
                  s[left] == s[right]) {

                int len = right - left + 1;

                // Found a longer palindrome
                if(len > maxLen) {
                    maxLen = len;
                    start = left;
                }

                // Expand outward
                left--;
                right++;
            }
        }

        // Extract the longest palindrome
        return s.substr(start, maxLen);
    }
};
