class Solution 
{
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        // vector<int>ans;
        // map<int, int>mp;
        // for(int i =0;i<nums.size();i++)
        // {
        //     mp[nums[i]]++;
        //     if(mp[nums[i]]>1)
        //     {
        //         ans.push_back(nums[i]);
        //         ans.push_back(nums[i]+1);
        //     }
        // }
        // return ans;
        int dup=-1,missing=-1;
        for(auto itr:nums)
        {
            if(nums[abs(itr)-1]<0)
                dup= abs(itr);
            else
                nums[abs(itr)-1]*=-1;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                missing=i+1;
        }
        vector<int>ans={dup,missing};
        return ans;
    }
};