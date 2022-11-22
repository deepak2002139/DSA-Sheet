class Solution {
public:
    int numSquares(int n) {
        // return rec(n);
        vector<int>dp(n+1,-1);
        return memo(n,dp);
    }
    
    int rec(int n){
        // base condition
        if(n==0)
            return 0;
        
        // Recursive condition
        int min_cnt=INT_MAX;
        for(int i=1;i<=sqrt(n);i++){
            int sqr=i*i;
            min_cnt=min(min_cnt, 1+rec(n-sqr));
        }
        return min_cnt;
    }
    
    int memo(int n,vector<int>&dp){
        // base condition
        if(n==0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        // Recursive condition
        int min_cnt=INT_MAX;
        for(int i=1;i<=sqrt(n);i++){
            int sqr=i*i;
            min_cnt=min(min_cnt, 1+memo(n-sqr,dp));
        }
        dp[n]=min_cnt;
        return min_cnt;
    }
};