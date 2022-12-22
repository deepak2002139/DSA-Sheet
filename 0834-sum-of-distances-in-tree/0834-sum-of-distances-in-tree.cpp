class Solution {
public:
    #define f(i,a,b) for(auto i=a;i<b;i++) 
    #define vl vector<ll>
    #define ll long long
    vector<ll>in,out,child;

    void child_count(vector<ll>adj[],ll curr,ll par){
        ll count=0;
        for(auto x:adj[curr]){
            if(x!=par){
                child_count(adj,x,curr);
                count+=(child[x]+1);
            }
        }
        child[curr]=count;
        return;
    }
 
    void dfs1(vector<ll>adj[],ll curr,ll par){
        ll count=0;
        for(auto x:adj[curr]){
            if(x!=par){
                dfs1(adj,x,curr);
                count+=(in[x]+child[x]+1);
            }
        }
        in[curr]=count;
        return;
    }
    
    void dfs2(vector<ll>adj[],ll curr,ll par,ll n){
        for(auto x:adj[curr]){
            if(x!=par){
                out[x]=(in[curr]+out[curr]-in[x]-child[x]-1)+(n-child[x]-1);
                dfs2(adj,x,curr,n);
            }
        }
        return;
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<ll>adj[n];
        in.resize(n);out.resize(n);child.resize(n);
        for(auto &x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        child_count(adj,0,-1);
        dfs1(adj,0,-1);
        dfs2(adj,0,-1,n);
        vector<int>answer;
        f(i,0,n){
            answer.push_back(in[i]+out[i]);
        }
        return answer;
    }
};