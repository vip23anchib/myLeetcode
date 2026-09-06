class Solution {
public:

    vector<vector<int>> ans;
    vector<int> curr;

    void solve(vector<int>& nums, int index)
    {
        
        int n=nums.size();
        if(index>=n){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[index]);
        solve(nums,index+1);

        curr.pop_back();

        solve(nums,index+1);

    }


    vector<vector<int>> subsets(vector<int>& nums)
    {
        solve(nums, 0);

        return ans;
    }
};
