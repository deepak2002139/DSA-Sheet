class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
          int ans=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        int presum=0;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            int rem=(presum%k);
            if(rem<0){
                rem+=k;
            }
            if(mp.find(rem)!=mp.end()){
                ans+=mp[rem];
            }
            mp[rem]+=1;
        }
        return ans;
        
    }
};