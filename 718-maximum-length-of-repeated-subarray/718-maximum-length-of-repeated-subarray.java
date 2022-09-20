class Solution {
    public int findLength(int[] nums1, int[] nums2) 
    {
        int ans =0;
        // int count=0;
        int n1=nums1.length;
        int n2=nums2.length;
        
        int [][] dp = new int [n1+1][n2+1];
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(nums1[i-1]==nums2[j-1] )
                {
                dp[i][j]= 1+ dp[i-1][j-1];
                ans=Math.max (ans,dp[i][j]);
                } 
                else dp[i][j]=0;
            }
        }
        return ans;
    }
}


// class Solution 
// {
// public int findLength(int[] nums1, int[] nums2) 
// {
// int n= nums1.length;
// int m= nums2.length;
// int ans=0;
// int dp[][]= new int[n+1][m+1];

//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=m;j++)
//         {
            
//             if(nums1[i-1]==nums2[j-1] )
//             {
//                 dp[i][j]= 1+ dp[i-1][j-1];
//                 ans=Math.max (ans,dp[i][j] );
//             } 
//             else dp[i][j]=0;
//         }
//     return ans;
// }
// }