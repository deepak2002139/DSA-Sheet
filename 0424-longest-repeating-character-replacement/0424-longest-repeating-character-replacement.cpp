class Solution 
{
public:
    int characterReplacement(string s, int k)
    {
            unordered_set<char>st;
            for(auto &e : s)
            {
                st.insert(e);
            }
            int ans = 0;
            for(auto &e : st)
            {
                int i = 0;
                int j = 0;
                int cnt = 0;
                int currLen = 0;
                while(j < s.length())
                {
                    if(s[j] == e)
                    {
                        currLen++;
                        j++;
                        ans = max(currLen, ans);
                    }
                    else
                    {
                        cnt++;
                        currLen++;
                        while(cnt > k && i <= j)
                        {
                            if(s[i] != e)
                            {
                                cnt--;
                            }
                            i++;
                            currLen--;
                        }
                        ans = max(currLen, ans);
                        j++;
                    }
                }
            }
            return ans;
		}
};