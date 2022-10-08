class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int st=i+1;
            int en=n-1;
            while(st<en){
                int sum = nums[i]+nums[st]+nums[en];
                int k=ans.size();
                if(sum==0 && (k==0 || (nums[st]!=ans[k-1][1] || nums[i]!=ans[k-1][0])))
                    ans.push_back({nums[i], nums[st], nums[en]});
                if(sum>0)
                    en--;
                else st++;
            }
        }
        return ans;
    }
};