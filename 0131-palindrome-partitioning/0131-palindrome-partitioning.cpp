class Solution {
public:
    bool check(string str)
    {
        bool flag= true;
        int n= str.size();
        if(n==1)
            return true;
        int i=0;
        int j=n-1;
        while(i<j)
        {
            if(str[i]!=str[j])
            {
                flag=false;
                break;
            }
            i++;j--;
        }
        return flag;
    }
//     vector<vector<string>> partition(string s)
//     {
        
//         vector<vector<string>>ans;
//         vector<string>res;
//         int n =s.size();
//         if(n==1)
//         {
//             res.push_back(s);
//             ans.push_back(res);
//             return ans;
//         }
//         int i=1;
//         for(int j=0;j<s.size()-i;j++)
//         {
//             for(i =1;i<=s.size();i++)
//             {
//                 if(check(s.substr(j,i)))
//                 {
//                     res.push_back(s.substr(j,i));
//                 }
//             }
//             ans.push_back(res);
//             res.clear();
//         }
//         return ans;
//     }
    void solve(string s,vector<vector<string>>& ans,vector<string> v){
    if(s.size()==0){
        ans.push_back(v);
        return;
    }
    for(int i=0;i<s.size();i++){
        string curr = s.substr(0,i+1);
        string pending = s.substr(i+1);
        if(check(curr)){
            v.push_back(curr);
            solve(pending,ans,v);
            v.pop_back();
        }
    }
}
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        solve(s,ans,v);
        return ans;
    }
};
