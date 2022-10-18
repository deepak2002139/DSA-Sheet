class Solution {
public:
    string countAndSay(int n) 
    {
        if(n==1)return string("1");
        string s = countAndSay(n-1);
        int m = s.size();
        int l = 0, r = 0;
        string ans;
        while(l<m)
        {
            while(s[r+1] == s[l] && r+1<m)
                r++;
            ans += to_string(r-l+1) + s[l];
            l = r = r+1;
        }
        return ans;
    }
};