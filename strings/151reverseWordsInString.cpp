/*
=========================================================
151. Reverse Words in a String
=========================================================

QUESTION
--------
Given a string s, reverse the order of the words.

Rules:
1. Remove leading spaces.
2. Remove trailing spaces.
3. Reduce multiple spaces between words to a single space.
4. Return the reversed sentence.

Example:

Input:
"  the   sky is blue  "

Output:
"blue is sky the"


=========================================================
THINKING PROCESS
=========================================================

Don't think about reversing first.

Ask yourself:

"What is the final answer made of?"

Answer:
Words.

So first extract every word.

Example:

"  the   sky is blue "

↓

["the", "sky", "is", "blue"]

↓

Reverse the vector

↓

["blue", "is", "sky", "the"]

↓

Join them using one space.

Done.


=========================================================
APPROACH
=========================================================

We solve the problem in THREE steps.

STEP 1
-------
Extract every word.

STEP 2
-------
Reverse the vector.

STEP 3
-------
Join all words using exactly one space.


=========================================================
HOW TO EXTRACT WORDS?
=========================================================

Maintain an index i.

For every iteration:

1. Skip all spaces.

2. Create a new empty string.

3. Collect characters until a space is found.

4. Store the word.

Repeat.

Visual Flow:

Outer while
      │
      ▼
Skip spaces
      │
      ▼
Create word=""
      │
      ▼
Read ONE complete word
      │
      ▼
Push into vector
      │
      ▼
Repeat


=========================================================
WHY TWO INNER WHILE LOOPS?
=========================================================

They perform DIFFERENT jobs.

First while:

while(i<n && s[i]==' ')

Job:
Skip useless spaces.

-----------------------------------

Second while:

while(i<n && s[i]!=' ')

Job:
Read one complete word.

So every iteration of the OUTER loop processes
EXACTLY ONE WORD.


=========================================================
WHY CHECK i<n INSIDE THE INNER LOOPS?
=========================================================

Outer while:

while(i<n)

checks ONLY before entering ONE iteration.

Inside that iteration,
i keeps changing.

Suppose

"hello"

After reading 'o'

i = 5
n = 5

If we wrote

while(s[i]!=' ')

it becomes

while(s[5]!=' ')

This is OUT OF BOUNDS.

Therefore every time we access s[i],
we first make sure

i<n

This prevents invalid memory access.


=========================================================
FLOW OF EXECUTION
=========================================================

Iteration 1

Outer while
    ↓
Skip spaces
    ↓
word=""
    ↓
Read "hello"
    ↓
Push "hello"

Iteration 2

Outer while
    ↓
Skip spaces
    ↓
word=""
    ↓
Read "world"
    ↓
Push "world"

End

Reverse vector

Join words.


=========================================================
IMPORTANT NOTE
=========================================================

string word="";

is CORRECT.

string word='';

is WRONG.

Reason:

""  -> String

''  -> Character (invalid if empty)

Always use

string word="";


=========================================================
TIME COMPLEXITY
=========================================================

O(n)

Each character is visited at most once.

Reversing vector is O(number of words).

Overall O(n).


=========================================================
SPACE COMPLEXITY
=========================================================

O(n)

Vector stores all words.


=========================================================
CODE
=========================================================
*/

class Solution {
public:
    string reverseWords(string s) {

        vector<string> words;

        int n = s.length();
        int i = 0;

        // Process one word per outer iteration
        while(i < n){

            // Skip all consecutive spaces
            while(i < n && s[i] == ' ')
                i++;

            // New empty string for the current word
            string word = "";

            // Read one complete word
            while(i < n && s[i] != ' '){
                word += s[i];
                i++;
            }

            // Store only non-empty words
            if(!word.empty())
                words.push_back(word);
        }

        // Reverse the order of words
        reverse(words.begin(), words.end());

        string ans = "";

        // Join words using a single space
        for(int i = 0; i < words.size(); i++){

            ans += words[i];

            // Don't add space after the last word
            if(i != words.size() - 1)
                ans += " ";
        }

        return ans;
    }
};
