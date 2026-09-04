// 344. Reverse String
// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

// Example 1:

// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]

class Solution {
public:
    void reverseString(vector<char>& s, int left, int right) {
        
        if (left >= right)
            return;

        swap(s[left], s[right]);

        reverseString(s, left + 1, right - 1);
    }

    void reverseString(vector<char>& s) {
        reverseString(s, 0, s.size() - 1);
    }
};
