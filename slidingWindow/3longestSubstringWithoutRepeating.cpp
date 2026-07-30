/*
=========================================================
        WHY "while" INSTEAD OF "if" ? (Sliding Window)
=========================================================

Pattern:

Expand Window
      ↓
Window becomes INVALID
      ↓
Shrink until VALID again
      ↓
Update Answer

---------------------------------------------------------

❌ WRONG:

if(window is invalid)
{
    shrink once;
}

Why?

Shrinking ONCE does NOT guarantee that the window
becomes valid.

Example:

String = "pwwkew"

Window = "pww"

Frequency:
p -> 1
w -> 2   ❌ Duplicate

Remove 'p' once:

Window = "ww"

Frequency:
w -> 2   ❌ Still duplicate

The window is STILL INVALID.

Using 'if' stops here and calculates the answer
using an invalid window, giving the wrong result.

---------------------------------------------------------

✅ CORRECT:

while(window is invalid)
{
    shrink window;
}

Keep removing characters from the LEFT until
the condition becomes valid again.

Example:

"pww"

Remove 'p'
→ "ww"   ❌ Still invalid

Remove first 'w'
→ "w"    ✅ Valid

NOW calculate the answer.

---------------------------------------------------------

INTERVIEW TRICK:

Ask yourself:

"Can ONE shrink always fix the window?"

YES  → use if

NO   → use while

---------------------------------------------------------

For this problem:

Window condition:
Every character frequency must be <= 1

After adding s[right],
keep shrinking until

mp[s[right]] == 1

Only then is the window valid.

---------------------------------------------------------

Golden Rule:

Never calculate the answer using an INVALID window.

Always:

Expand
→ While invalid, shrink
→ Update answer

=========================================================
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int>mp;
        int n=s.length();
        int left=0;
        int ans=0;

        for(int right=0;right<n;right++){
            mp[s[right]]++;
            
            while(mp[s[right]]>1){
                mp[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
    return ans;
    }
};
