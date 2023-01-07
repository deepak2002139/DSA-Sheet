// class Solution {
// public:
//     void helper(vector<vector<int>>&ans,vector<int>&candidates,int sum,int i,int target,vector<int>res)
//     {
//         if(i>=candidates.size())
//             return;
//         if(target==sum)
//         {
//             ans.push_back(res);
//             return;
//         }
//         sum+=candidates[i];
//         res.push_back(candidates[i]);
//         helper(ans,candidates,sum,i+1,target,res);
//         helper(ans,candidates,sum+candidates[i],i+1,target,res);
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
//     {
//        vector<vector<int>>ans;
//         vector<int>res;
//         helper(ans,candidates,0,0,target,res);
//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0,target,candidates,ans,ds);
        return ans;
    }

    void findCombination(int index, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds ){

        if(target==0)
        {
            ans.push_back(ds);
            return;
        }

        for(int i=index;i<candidates.size();i++)
        {
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            findCombination(i+1,target-candidates[i],candidates,ans,ds);
            ds.pop_back();


        }
    }
};