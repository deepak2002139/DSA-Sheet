class Solution {
public:
    bool checkUnique(string &s){
        int hash[26]={0};
        for(int i=0; i<s.size(); i++){
            hash[s[i]-97]++;
        }
        for(int i=0; i<26; i++){
            if(hash[i]>1){
                return false;
            }
        }
        return true;
    }

    int cal(int ind, string s, vector<string> &v, map<string,int> &dp){
        if(!checkUnique(s)){
            return 0;
        }
        if(ind<0){
            return s.size();
        }
        
        if(dp.find(s)!=dp.end()){
            return dp[s];
        }
        
        return dp[s]=max(cal(ind-1,s+v[ind],v,dp),cal(ind-1,s,v,dp));
    }

    int maxLength(vector<string>& v) {
        int n=v.size();
        map<string,int> dp;
        return cal(n-1,"",v,dp);
    }
};