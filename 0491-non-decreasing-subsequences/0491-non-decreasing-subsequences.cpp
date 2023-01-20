class Solution
{
    public:
        void solve(vector<int> &res, vector<int> &nums, set< vector< int>> &ans, int i)
        {
            if (i == nums.size())
            {
                if (res.size() >= 2)
                {
                    ans.insert(res);
                   	// return;
                }
                return;
            }
            if(res.empty()||res[res.size()-1]<=nums[i])
            {
            res.push_back(nums[i]);/*very important line i am not  adding this element thats why showing me error multiple time be carefull next time.*/
            solve(res, nums, ans, i + 1);
            res.pop_back();
            }
            solve(res, nums, ans, i + 1);
        }
    vector<vector < int>> findSubsequences(vector<int> &nums)
    {
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        vector<int> res;
        set<vector < int>> ans;
        solve(res, nums, ans, 0);
        return vector<vector < int>> (ans.begin(), ans.end());
    }
};