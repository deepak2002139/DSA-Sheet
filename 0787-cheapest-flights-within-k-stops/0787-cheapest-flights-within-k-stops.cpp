class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int ,vector<pair<int,int>>> graph;
        for(auto it: flights){
            graph[it[0]].push_back({it[1],it[2]});
        }
        vector<int> cost(n,INT_MAX);

        queue<pair<int,int>>q;
        q.push({src,0});
        cost[src]=0;
        int steps=0;
        while(!q.empty() && steps<=k){
            int sz= q.size();
            
            while(sz--){
                int u = q.front().first;
                int p = q.front().second;
                q.pop();
                for(auto v:graph[u]){
                    int node= v.first;
                    int ncost= v.second;
                    if(cost[node]>p+ncost){
                        cost[node]=p+ncost;
                        q.push({node,p+ncost});
                    }
                }
            }
            steps++;
        }
        if(cost[dst]==INT_MAX)
             return -1;
        return cost[dst];
    }
};