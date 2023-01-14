class Solution 
{
public:
    string smallestEquivalentString(string s1,string s2,string baseStr)
    {
        vector<unordered_set<int>> rel(26);
        for(int i=0; i<26; i++)
        {
            rel[i].insert(i);
        }
        for(int i=0;i<s1.size();i++)
        {
            rel[s2[i]-'a'].insert(s1[i]-'a');
            rel[s1[i]-'a'].insert(s2[i]-'a');
        }
        string ans = "";
        for(int i=0;i<baseStr.size();i++)
        {
            int idx = baseStr[i]-'a';
            queue<int> q;
            vector<bool> visited(26,false);
            q.push(idx);
            visited[idx]=true;
            int minCh=idx;
            while(!q.empty())
            {
                int cur=q.front();
                q.pop();
                minCh = min(minCh, cur);
                for(int j: rel[cur])
                {
                    if(!visited[j])
                    {
                        q.push(j);
                        visited[j]=true;
                    }
                }
            }
            ans+='a'+minCh;
        }
        return ans;
    }
};