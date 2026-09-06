// Combination Sum I — LeetCode 39

// current stores the combination currently being built.
// ans stores all valid combinations.

// BASE CASE:
// If index reaches the end, stop.
// If target == 0, current is a valid combination → add it to ans.

// At each step, we try to use candidates[index].

// If candidates[index] <= target:
//     Choose the current candidate → push_back.

//     RECURSE with:
//     target - candidates[index]
//     SAME index
//
//     SAME index is IMPORTANT because the same number
//     can be chosen unlimited times.
//
//     Example:
//     candidates = [2,3], target = 7
//     2 → 2 → 3 = 7
//
//     After recursion, pop_back() to undo the choice
//     and try other possibilities.

// Key idea:
// CHOOSE → RECURSE → UNCHOOSE

// For Combination Sum I:
//     solve(..., index)
//     → reuse allowed

// For Combination Sum II:
//     solve(..., index + 1)
//     → each element used only once

// Sorting is useful so that when candidates[index] > target,
// we know no useful combination can be formed from that point.

// Mental pattern:
// target becomes smaller after every choice.
// target == 0 → valid answer.
// target < 0 / candidate > target → stop that branch.


class Solution {
public:

    void solve(vector<int>& candidates, int target, int index, vector<int>& current,vector<vector<int>>& ans) {
        if(index==candidates.size()){
            if(target==0){
                ans.push_back(current);
            }
            return;
        }

        if(candidates[index]<=target){
            current.push_back(candidates[index]);

            solve(candidates,target-candidates[index],index,current,ans);

            current.pop_back();
        }

        solve(candidates,target,index+1,current,ans);
        
    }


    vector<vector<int>> combinationSum(vector<int>& candidates,
                                        int target) {

        vector<vector<int>> ans;
        vector<int> current;

        solve(candidates, target, 0, current, ans);

        return ans;
    }
};

