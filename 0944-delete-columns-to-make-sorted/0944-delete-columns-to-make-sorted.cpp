class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        vector<vector<char>> vec(strs.size(),vector<char>(n));
        for(int i=0;i<strs.size();i++)
        {
            for(int j=0;j<strs[i].size();j++)
            {
                vec[i][j]=strs[i][j];
            }
        }
        int ans=0;
        for(int j=0;j<n;j++)
        {
            for(int i=1;i<strs.size();i++)
            {
                if(vec[i][j]<vec[i-1][j])
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};