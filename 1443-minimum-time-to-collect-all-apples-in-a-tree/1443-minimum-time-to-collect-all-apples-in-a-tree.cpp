class Solution {
public:
    int dfs(vector<vector<int>> & graph,vector<bool> & map,int p=0,int c=0){
        int ans = 0;
        for(int ngb : graph[c]){
            if(ngb == p) continue;
            ans += dfs(graph,map,c,ngb);
        }
        if(ans != 0) ans += (p == 0 && c == 0) ? 0 : 2;
        else{
            ans += map[c] ? (p == 0 && c == 0) ? 0 : 2 : 0;
        } 
        return ans;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        map<int,bool> map;
        //cout<<graph.size();
        for(int i = 0;i < n-1;i++){
            vector<int> v = edges[i];
            //cout<<" sd";
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        return dfs(graph,hasApple);
    }
};