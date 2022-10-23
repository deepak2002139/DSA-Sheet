class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        int ans=0;
        unordered_map<int , int> m ;
        for(auto it :nums)
            m[it]++;
        for(auto it :m)
            if(it.second>=2)
                ans=it.first;
        return ans ;
    }
};