/* An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        bool isIncreasing=true;
        bool isDecreasing=true;
        for (int i=1;i<n;i++){
            if (nums[i]>nums[i-1]){
                isDecreasing=false;
            }
            else if(nums[i]<nums[i-1]){
                isIncreasing=false;
            }
        }
        if (isIncreasing || isDecreasing){
            return true;
        }
        else{
            return false;
        }
        
    }
};

/* solution:
Initialize two boolean variables: isIncreasing and isDecreasing to false
Start the loop from index 1 compare with its previous element.
If an element is greater than its previous element then set isIncreasing=true(means the array is increasing)
If an element is smaller than its previous element then set isDecreasing=true(means the array is decreasing)
if both isIncreasing and isDecreasing are true then return false and break as the array is neither increasing
 nor decreasing and we don't have to continue the loop.
*/