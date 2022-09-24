class Solution 
{
public int maximumScore(int[] nums, int[] multipliers)
{
    int i=0;
    int j=nums.length-1;
    
    int[][] dp=new int[multipliers.length][multipliers.length];
    for(int []d: dp) Arrays.fill(d, -(int)1e9);
    return call(i, j, 0, nums, multipliers, dp);
}

public int call(int i, int j, int k, int[]nums, int[] multipliers, int[][]dp)
{
    if(k==multipliers.length) return 0;
    
    int N=nums.length; int M=multipliers.length;
    if(dp[i][j-N+M]!=-(int)1e9) return dp[i][j-N+M];
    int a=call(i+1, j, k+1, nums, multipliers,dp)+nums[i]*multipliers[k];
    int b=call(i, j-1, k+1, nums, multipliers,dp)+nums[j]*multipliers[k];
    
    return dp[i][j-N+M]=Math.max(a,b);
}
}