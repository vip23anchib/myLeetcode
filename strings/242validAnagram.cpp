/*
=========================================================
242. Valid Anagram
=========================================================

THINKING
--------
Two strings are anagrams if they contain
the SAME characters with the SAME frequencies.

Example

listen

↓

l : 1
i : 1
s : 1
t : 1
e : 1
n : 1

silent

↓

l : 1
i : 1
s : 1
t : 1
e : 1
n : 1

Frequencies match ✔

---------------------------------------------------------
APPROACH
---------------------------------------------------------

1. If lengths are different
      -> return false.

2. Count frequency of every character in s.

3. Decrease frequency using characters of t.

4. If every frequency becomes 0
      -> strings are anagrams.

Otherwise
      -> false.

---------------------------------------------------------
TIME COMPLEXITY
---------------------------------------------------------

O(n)

---------------------------------------------------------
SPACE COMPLEXITY
---------------------------------------------------------

O(1)

(HashMap stores at most 26 lowercase letters)

=========================================================
*/

class Solution {
public:
    bool isAnagram(string s, string t) {

        // Stores frequency of each character
        unordered_map<char,int> mp;

        // Different lengths can never be anagrams
        if(s.length() != t.length())
            return false;

        // Count characters of first string
        for(int i=0; i<s.length(); i++)
            mp[s[i]]++;

        // Remove characters using second string
        for(int i=0; i<t.length(); i++)
            mp[t[i]]--;

        // Every frequency should become zero
        for(auto x : mp){
            if(x.second != 0)
                return false;
        }

        return true;
    }
};
