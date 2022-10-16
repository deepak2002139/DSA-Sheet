class Solution {
public:
    int dfs(vector<int>& jd, vector<vector<int>>& t, int d, int i)
    {
        if(d==1)
        {
            int maxv = 0;
            for(int idx = i; idx < jd.size(); idx++)
                maxv = max(maxv, jd[idx]);
            return maxv;
        }
        if(t[d][i] != -1)
            return t[d][i];
        int l = 0;
        int ans = INT_MAX;
        for(int idx = i; idx < jd.size()-d+1; idx++)
        {
            l = max(l, jd[idx]);
            int r = dfs(jd, t, d-1, idx+1);
            ans = min(ans, l+r);
        }
        return t[d][i] = ans;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d>jobDifficulty.size())
            return -1;
        vector<vector<int>> t(d+1, vector<int> (jobDifficulty.size()+1));
        for(int i=0; i<=d; i++)
        {
            for(int j=0; j<=jobDifficulty.size(); j++)
                t[i][j] = -1;
        }
        return dfs(jobDifficulty, t, d, 0);
    }
};