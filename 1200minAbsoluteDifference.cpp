/*
Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

    a, b are from arr
    a < b
    b - a equals to the minimum absolute difference of any two elements in arr

*/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int mini = INT_MAX;
        int n = arr.size();

        for (int i = 0; i < n - 1; i++) {
            mini = min(mini, arr[i + 1] - arr[i]);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] - arr[i] == mini) {
                ans.push_back({arr[i], arr[i + 1]});
            }
        }

        return ans;
    }
};

