class Solution 
{
public:
    string frequencySort(string s) 
    {
        unordered_map<char, int> m;
        for (auto c : s)
        {
            ++m[c];
        }
        auto pred = [&m] (char a, char b)
        {
            return m[a]>m[b]or(a>b and(m[a]==m[b]));
        };
        sort(s.begin(),s.end(),pred);
        return s;
    }
};