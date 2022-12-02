class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        // string curr1 = word1,curr2 = word2;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        map<int,int> mp3;
        map<int,int> mp4;
        string curr1 = "";
        string curr2 = "";
        int maxFre1  = 0, maxFre2 = 0;
        for(auto x : word1)
        {
           mp1[x]++;
        }
        for(auto x : word2)
        {
           mp2[x]++;
        }
        for(auto x : mp1)
        {
           curr1.push_back(x.first);
           maxFre1 = max(maxFre1,x.second);
           mp3[x.second]++;
        }
        for(auto x : mp2)
        {
           curr2.push_back(x.first);
           maxFre2 = max(maxFre2,x.second);
           mp4[x.second]++;
        }
        if(maxFre1 != maxFre2)
           return false;
        sort(curr1.begin(),curr1.end());
        sort(curr2.begin(),curr2.end());
        if(curr1 != curr2)
            return false;
        if(m != n)
           return false;
        auto it1 = mp3.begin();
        auto it2 = mp4.begin();
        while(it1 != mp3.end() && it2 != mp4.end())
        {
            if(it1->second != it2->second)
                 return false;
            it1++;
            it2++;
        }
        if( m == 1 && word1[0] != word2[0])
           return false;
        return true;
    }
};