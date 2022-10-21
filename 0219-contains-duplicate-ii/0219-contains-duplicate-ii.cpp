class Solution 
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        if(k==0)return false;
        
        unordered_map<int,int>elementToIndexMap;
        for(int i=0;i<nums.size();i++) 
        {
            if(elementToIndexMap.find(nums[i]) != elementToIndexMap.end() && i-elementToIndexMap[nums[i]] <= k)
                return true;
            elementToIndexMap[nums[i]]=i;
        }
        
        return false;
    }
};
