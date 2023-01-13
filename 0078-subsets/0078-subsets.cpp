class Solution
{
    public:
        vector<vector < int>> subsets(vector<int> &nums)
        {
            int n = nums.size();
            int count = (1 << n);
            vector<vector < int>> ans;
            for (int m = 0;m<count; m++)
            {
                vector<int> subset;
                for (int i = 0; i < n; i++)
                {
                    if(m&1<<i)
                    {
                        subset.push_back(nums[i]);
                    }
                }
                ans.push_back(subset);
            }
            return ans;
        }
};
