class Solution {
public:
    string reverseWords(string s) 
    {
         stringstream ss(s) ;
    vector<string> s1 ;
    string word ;
    
    while(ss >> word)
        s1.push_back(word) ;
    
    string ans ;
    for(int i = s1.size()-1 ; i > 0 ;i-- ) 
    {
        ans += s1[i] ;
        ans += " " ;
    }
    
    
    ans += s1[0] ;
    return ans ;
        
    }
};