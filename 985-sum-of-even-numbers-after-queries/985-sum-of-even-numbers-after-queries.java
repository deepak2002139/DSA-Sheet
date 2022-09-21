class Solution 
{
    public int[] sumEvenAfterQueries(int[] nums, int[][] queries)
    {
        int preSum=0;
        for(int x: nums) preSum=(x%2==0)?preSum+x:preSum;
        
        int ans[]=new int[queries.length];
        int index=0;
        for(int []q: queries) 
        {
            int val=q[0];
            int idx=q[1];
            preSum=(nums[idx]%2==0)?preSum-nums[idx]:preSum;
            nums[idx]+=val;
            ans[index++]=preSum=(nums[idx]%2==0)?preSum+nums[idx]:preSum;
        }
        return ans;
    }
}