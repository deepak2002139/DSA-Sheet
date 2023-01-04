class Solution
{
    public:
        void solve(set<vector < int>> &ans, int i, vector< int > res, vector< int > &nums)
        {
            if (i == nums.size())
            {
                ans.insert(res);
                return;
            }
            solve(ans, i + 1, res, nums);
            res.push_back(nums[i]);
            solve(ans, i + 1, res, nums);
            res.pop_back();
        }
    vector<vector < int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(),nums.end());
        set<vector < int>> ans;
        vector<vector < int>> ans2;
        vector<int> res;
        solve(ans, 0, res, nums);
        for (auto it: ans)
        {
            ans2.push_back(it);
        }
        return ans2;
    }
};
// class Solution 
// {
// private:
//     void helper(set<vector < int>> &s,vector<int> &v,vector<int>& nums,int i, int n)
//     {      
//         if(i == n){
//             s.insert(v);
//             return;
//         }
//         helper(s,v,nums,i+1,n);
//         v.push_back(nums[i]);
//         helper(s,v,nums,i+1,n);
//         v.pop_back();    
//     }
// public:
//     vector<vector < int>> subsetsWithDup(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         vector<vector < int>> res;
//         vector<int> v;
//         set<vector < int>> s;
//         helper(s,v,nums,0,nums.size());
//         for(auto x : s){
//             res.push_back(x);
//         }
//         return res;
//     }
// };