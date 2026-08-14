// LeetCode 451: Sort Characters By Frequency
// Goal: Return string with characters sorted by DECREASING frequency.
//
// Example:
// "tree" → "eetr"
// e appears 2 times, t/r appear 1 time
//
// APPROACH:
// 1. Count frequency of every character
// 2. Put (character, frequency) into a vector
// 3. Sort vector by frequency HIGH → LOW
// 4. Build answer using the frequency

class Solution {
public:
    string frequencySort(string s) {

        // 1. COUNT FREQUENCY
        // mp[character] = number of times it appears
        unordered_map<char, int> mp;

        for(char c : s) {
            mp[c]++;
        }

        // 2. Convert map → vector of pairs
        // Each element: (character, frequency)
        // Needed because we want to SORT them
        vector<pair<char,int>> arr(mp.begin(), mp.end());
      //--------------------------------------------------
        // OR YOUN CAN DO THE FOLLOWING:
        // vector<pair<char,int>> arr;
        // for(auto &it : mp) {
        //     arr.push_back(it);
        // }
      //---------------------------------------------------
        // 3. SORT by frequency: HIGH → LOW
        // .first  = character
        // .second = frequency
        sort(arr.begin(), arr.end(),
            [](auto &a, auto &b) {
                return a.second > b.second;
            });

        // 4. BUILD ANSWER
        string ans = "";

        for(auto &it : arr) {

            // it.first  = character
            // it.second = frequency
            //
            // append(frequency, character)
            // → adds the character frequency times
            //
            // Example:
            // it = ('e', 3)
            // ans.append(3, 'e') → "eee"
            ans.append(it.second, it.first);
        }

        return ans;
    }
};
