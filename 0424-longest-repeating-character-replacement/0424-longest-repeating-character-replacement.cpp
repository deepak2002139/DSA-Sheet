class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int  n = s.size();
        int ans =0;
        int i =0 , j =0, maxi =0;
        unordered_map<char , int> mp ;
        while(j<n)
        {
            while(j<n)
            {
            mp[s[j]]++;
            maxi= max(mp[s[j]],maxi);
                if(mp.size()>1 && j-i+1-maxi>k)
                    break;
                ans= max(ans,j-i+1);
                j++;
            }
            if(maxi==mp[s[i]])
                maxi--;
            mp[s[i]]--;
            if(mp[s[i]]==0)
                mp.erase(s[i]);
            i++;
            j++;
            
        }
        return ans;
    }
};