class Solution 
{
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        if(nums.size()<2)
        return false;
        unordered_map<int,int> mp;
        mp[0]=-1;
        int curr_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            curr_sum+=nums[i];
            curr_sum%=k;
            if(mp.find(curr_sum)!=mp.end())
            {
                if(i-mp[curr_sum]>1)
                return true;
            }
            else
            {
                mp[curr_sum]=i;
            }
            
        }
        return false;
    }
};