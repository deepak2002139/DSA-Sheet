class Solution {
public:
    int findGCD(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int div=0;
        for(int i=1;i<=nums[0];i++){
            if(nums[0]%i==0 && nums[nums.size()-1]%i==0){
                div=i;
            }
        }
        return div;
    }
};