class Solution {
    public int maxSubArray(int[] nums) 
    {
        int n=nums.length;
        int res=nums[0];
        int [] dpmax= new int [n];
        dpmax[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            dpmax[i]=Math.max(dpmax[i-1]+nums[i],nums[i]);
            res=Math.max(res,dpmax[i]);
        }
        return res;
        
    }
}