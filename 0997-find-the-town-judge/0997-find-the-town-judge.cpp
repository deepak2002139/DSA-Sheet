class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>mp(n+1);
        vector<vector<int>>m(n+1);
        for(auto i:trust)
        {
            mp[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        for(int i=1;i<=n;i++)
        {
            if(mp[i].size()==0 && m[i].size()==n-1)
                return i;
        }
        return -1;
    }
};