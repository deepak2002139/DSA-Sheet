class Solution
{
public:
    int solve(string s,int idx,vector<int>&dp)
    {
        if(s[0]=='0')
        return 0;
        if(idx==0||idx==1)
        return 1;
        if(dp[idx]!=-1)
        return dp[idx];
        int output=0;
        if(s[idx-1]>'0')
        output+=solve(s,idx-1,dp);
        if(s[idx-2]=='1'||(s[idx-2]=='2'&&s[idx-1]<'7'))
        output+=solve(s,idx-2,dp);
        return dp[idx]=output;
    }
    int numDecodings(string s) 
    {
        vector<int> dp(s.size()+1,-1);
        return solve(s,s.size(),dp);
        
    }
};