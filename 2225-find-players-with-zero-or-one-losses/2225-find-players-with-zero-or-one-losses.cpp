class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {
        vector<vector<int>>ans;
        vector<int>temp1;
        vector<int>temp2;
        // unordered_map<int,int>mp;
        map<int,int>mp;
        int n=matches.size();
        // for(int i=0;i<n;i++)
        // {
        //     mp[matches[0][0]]++;
        //     mp[matches[0][1]]++;
        // }
        for(auto v : matches)
        {
            mp[v[0]]+=0;
            mp[v[1]]++;
        }
        for(auto it:mp)
        {
            if(it.second==0)
            {
                temp1.push_back(it.first);
            }
            if(it.second==1)
            {
                temp2.push_back(it.first);
            }
        }
//         reverse(temp1.begin(),temp1.end());
//         reverse(temp2.begin(),temp2.end());
        
        ans.push_back(temp1);
        ans.push_back(temp2);
        return ans;
    }
};