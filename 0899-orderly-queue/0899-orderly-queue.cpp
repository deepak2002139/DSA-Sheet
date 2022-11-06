class Solution {
public:
    
    //very easy problem
    string orderlyQueue(string s, int k) {
        
        //just have to calculate for k==1, 
		//when s = "cba", --> cbacba
        if(k==1)
        {
            int n=s.length();
            string doublestring = s+s;      //append same string to s
            string ans = s;
            
            for(int i=1; i<n; i++)
            {
                string str = doublestring.substr(i,n);
                
                if(str < ans)
                {
                    ans = str;
                }
            }
            return ans;
        }
        
        sort(s.begin(), s.end());
        return s;
    }
};