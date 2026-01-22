#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> chunkArray(vector<int>& arr, int size) {
    vector<vector<int>> result;

    for (int i = 0; i < arr.size(); i += size) {
        vector<int> chunk;
        for (int j = i; j < i + size && j < arr.size(); j++) {
            chunk.push_back(arr[j]);
        }
        result.push_back(chunk);
    }

    return result;
}

/*
Given an array arr and a chunk size size, return a chunked array.
A chunked array contains the original elements in arr, but consists of subarrays each of length size. 
The length of the last subarray may be less than size if arr.length is not evenly divisible by size.
Please solve it without using lodash's _.chunk function.

Example 1:

Input: arr = [1,2,3,4,5], size = 1
Output: [[1],[2],[3],[4],[5]]
Explanation: The arr has been split into subarrays each with 1 element.

*/