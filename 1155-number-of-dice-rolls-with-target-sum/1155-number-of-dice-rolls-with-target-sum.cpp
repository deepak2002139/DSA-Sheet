// class Solution 
// {
// public:
//     void helper(int count,int n, int k,int target)
//     {
//         if(target<1)
//             return;
//         if(target==0)
//         {
//             count++;
//             return;
//         }
//         for(int i=0;i<k;i++)
//         {
//             helper(count,n,k,target-i);
//         }
//     }
//     int numRollsToTarget(int n, int k, int target)
//     {
//         if(n==0||k==0||target==0)
//             return 0;
//         int count=0;
//         while(n--)
//         for(int i=0;i<k;i++)
//         {
//             helper(count,n,i,target-i);
//         }
//         return count;
//     }
// };

class Solution {
private:
    const int mod = 1e9 + 7;
    long long dp[31][10001];
    long long solve(int k,int n,int target){
        if(target < 0) return 0;
        if(!n) return target == 0;

        if(dp[n][target] != -1) return dp[n][target];

        long long ans = 0;
        for(int i=1;i<=k;i++)
            ans = (ans + solve(k,n-1,target-i)) % mod;

        return dp[n][target] = ans;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof dp);
        return solve(k,n,target);
    }
};