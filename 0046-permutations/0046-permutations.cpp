class Solution 
{
public:
    void solve(vector<vector<int>>&ans, vector<int>&nums,int idx)
    {
        if(idx==nums.size()-1)
        {
           ans.push_back(nums);
            return;
        }
        // ans.push_back(nums);
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[i],nums[idx]);
            solve(ans,nums,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>>ans;
        vector<int>res;
        int idx=0;
        solve(ans,nums,idx);
        sort(ans.begin(),ans.end());
        return ans;
    }
};