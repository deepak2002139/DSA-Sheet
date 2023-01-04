class Solution {
public:
    void f(int idx , vector<int> &subset , vector<vector<int>> &ans , vector<int> &nums){
        ans.push_back(subset);
        for(int i=idx ; i<nums.size() ; i++){
            if(i != idx && nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            f(i+1 , subset , ans , nums);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin() , nums.end());
        f(0 , temp , ans , nums);
        return ans;
    }
};