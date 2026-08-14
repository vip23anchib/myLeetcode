class Solution {
public:
    int romanToInt(string s) {

        // Roman symbol -> value
        unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int ans = 0;

        // Check every character with the character AFTER it
        // Last character is handled separately
        for(int i = 0; i < s.length() - 1; i++) {

            int curr = mp[s[i]];
            int next = mp[s[i + 1]];

            // Smaller before larger → SUBTRACT
            if(curr < next)
                ans -= curr;

            // Otherwise → ADD
            else
                ans += curr;
        }

        // Add the last character
        ans += mp[s.back()];

        return ans;
    }
};

// Roman string
//      ↓
// Map characters to values
//      ↓
// Look at current + next
//      ↓
// current < next ?
//    /       \
//  YES       NO
//   ↓         ↓
// SUBTRACT   ADD
//      ↓
// Add last character
//      ↓
// Return answer
