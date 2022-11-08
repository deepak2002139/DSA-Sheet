class Solution {
public:
    bool check(char a , char b)
    {
        if(a>='A' && a<='Z'&& b>='a'&&b<='z')
        {
            if(tolower(a)==b)
            return true;
        }
        else if(a>='a'&& a<='z'&& b>='A'&& b<='Z')
        {
            if(tolower(b)==a)
                return true;
        }
        return false;
    }
            
    string makeGood(string s)
    {
        if(s.length() == 1)
            return s;
        // int n = s.size();
        // int i=0;
        for(int i=0;i<s.length();i++)
        {
            if(check(s[i],s[i+1]))
            {
                s.erase(s.begin()+i+1);
                s.erase(s.begin()+i);
                if(i == 0)
                    i--;
                else
                    i = i - 2;  
            }
            
        }
        return s;
        
    }
};