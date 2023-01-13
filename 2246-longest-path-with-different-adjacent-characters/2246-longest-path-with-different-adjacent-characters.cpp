class Solution {
public:   
    //same as 124. Binary Tree Maximum Path Sum
    int ans;
    int dfs(unordered_map<int,vector<int>> &adj,string &s,int curr,int parent){
    
      int largest = 0;
      int second_largest = 0;
      for(auto &child : adj[curr]){
          if(child==parent)
             continue;

          int child_longest_length =dfs(adj,s,child,curr);
          if(s[child]==s[curr])
             continue;

          if(child_longest_length>second_largest){     //nothing just find the largest and second largest:
               second_largest =child_longest_length;
          }
          if(second_largest>largest){
              swap(largest,second_largest);
          }
  
       
      }

        int koi_ek_acha = max(largest,second_largest)+1;
        int only_one_acha = 1;
        int nicha_hi_mil_gya = largest+second_largest+1;
  
        ans=max({ans,koi_ek_acha,only_one_acha,nicha_hi_mil_gya});
        return max(koi_ek_acha,only_one_acha);      
    }
    
    int longestPath(vector<int>& parent, string s) {
        unordered_map<int,vector<int>> adj;
        for(int i=1;i<parent.size();i++){
            int u = i;
            int v = parent[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       ans=INT_MIN;
       dfs(adj,s,0,-1);
       return ans;
    }  
};