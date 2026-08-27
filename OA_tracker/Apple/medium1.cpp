/*
QUESTION:

You are given a list of shots made by players in a game.

Each shot is represented as:
    "name RESULT"

where RESULT is either:
    HIT
    MISS

For each player:
    miss_count = number of MISS shots / total number of shots

Given a threshold, return the names of all players whose
miss_count is GREATER than the threshold.

Example:

Input:
    {
        "alice MISS",
        "alice HIT",
        "alice MISS",
        "claire MISS",
        "claire HIT"
    }

Threshold = 0.3

alice:
    MISS = 2
    Total = 3
    Miss count = 2/3 = 0.667 > 0.3  -> include

claire:
    MISS = 1
    Total = 2
    Miss count = 1/2 = 0.5 > 0.3   -> include

Output:
    {"alice", "claire"}


------------------------------------------------------------
APPROACH:
------------------------------------------------------------

We need to keep track of two things for every player:

    1. Total number of shots
    2. Number of MISS shots

We can store both in ONE hashmap:

    unordered_map<string, pair<int,int>> mp;

For every player:

    mp[name].first  = total shots
    mp[name].second = number of MISS shots

For every shot:

    - Extract name and result from the string
    - Increase total shots
    - If result == "MISS", increase miss count

After processing all shots:

    miss_count = misses / total

If miss_count > threshold:
    add the player to answer.


IMPORTANT:
Use double division here.

    (double)misses / total

Otherwise, if both are integers:

    misses / total

C++ will perform INTEGER division, which would give incorrect
results such as:

    2 / 3 = 0

instead of:

    2 / 3 = 0.666...


------------------------------------------------------------
TIME COMPLEXITY:
------------------------------------------------------------

Let n = number of shots.

Processing all shots:
    O(n) average

Processing all unique players:
    O(n) in the worst case

Overall:
    O(n) average

Space:
    O(n) in the worst case
*/


#include <bits/stdc++.h>
using namespace std;

vector<string> findPlayers(vector<string>& nums, double threshold) {

    /*
        mp[name].first  -> total number of shots
        mp[name].second -> number of MISS shots
    */

    unordered_map<string, pair<int, int>> mp;


    // Process every shot
    for (string s : nums) {

        string name;
        string result;

        /*
            stringstream breaks the string into space-separated parts.

            Example:
                s = "alice MISS"

            After:
                ss >> name >> result;

            name   = "alice"
            result = "MISS"
        */

        stringstream ss(s);

        ss >> name >> result;


        // Every entry represents one shot
        mp[name].first++;


        // If the shot was a MISS, increase miss count
        if (result == "MISS") {
            mp[name].second++;
        }
    }


    vector<string> ans;


    // Check every player
    for (auto &it : mp) {

        string name = it.first;

        int total = it.second.first;
        int misses = it.second.second;


        /*
            Cast misses to double so that we get
            decimal division.

            Example:
                2 / 3

            Without casting:
                2 / 3 = 0

            With casting:
                (double)2 / 3 = 0.666...
        */

        double missCount = (double)misses / total;


        // Player crosses the threshold
        if (missCount > threshold) {
            ans.push_back(name);
        }
    }


    return ans;
}
