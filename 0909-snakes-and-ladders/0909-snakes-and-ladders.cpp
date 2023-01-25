// class Solution
// {
//     public:
//         void solve(vector<pair<int,int>>V1,vector< vector< int>> board, int &ans, int i, int j, int &res, int &count)
//         {
//             count++;
//             if (i==0 && j == 0)
//             {
//                 ans=min(ans,count);
//                 return;
//             }
//             if (board[i][j] != -1)
//             {
//                 int i = V[V[res].first + board[i][j]].second.first;
//                 int j = V[V[res].first + board[i][j]].second.second;
//             }
//             solve(V, board, ans, i, j, res + 1);
//             solve(V, board, ans, i, j, res + 2);

//             solve(V, board, ans, i, j, res + 3);
//             solve(V, board, ans, i, j, res + 4);

//             solve(V, board, ans, i, j, res + 5);
//             solve(V, board, ans, i, j, res + 6);
//         }
//     int snakesAndLadders(vector<vector < int>> &board)
//     {
//         int res=1;
//         int count = 1;
//         int n = board.size();
//         int m = board[0].size();
//         int ans = INT_MAX;
//         vector<pair<int,int>> V;
//         res[n - 1][0] = 1;
//         for (int i=n-1;i>=0;i--)
//         {
//             for (int j=0;j<m;j++)
//             {
//                 res.push_back(count,{i,j});
//                 count++;
//             }
//             if (i-1>=0)
//             {
//                 i--;
//                 for(int j =m-1; j >= 0; j--)
//                 {
//                     res.push_back(count,{i,j});
//                     count++;
//                 }
//             }
//         }
//         int count=1;
//         solve(V,board,ans,n-1,0,res,count);
//         return ans;
//     }
// };
class Solution {
public:
    int dijkstra(int src, int tar, vector<int>& a)
    {
        vector<int>dis(tar + 2, 1e5);
        priority_queue<pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>>pq;
        dis[src] = 0;
        pq.push({ 0,src });
        while (!pq.empty())
        {
            int u = pq.top().second;
            int c = pq.top().first;
            pq.pop();
            if (u == tar)
            {
                return c;
            }
            
            for (int i = 1; i <= 6; i++)
            {
                if (i + u > tar)
                    break;
                int v;
                if (a[i + u] != -1)
                    v = a[i + u];
                else
                    v = i + u;
                if (dis[v] > dis[u] + 1)
                {
                    dis[v] = dis[u] + 1;
                    pq.push({ dis[v],v });
                }
            }
        }
        return -1;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        reverse(board.begin(), board.end());
        vector<int>a;
        a.push_back(0);
        int n = board.size();
        n *= n;
        int m = 0;
        for (auto i : board)
        {
            if (m & 1)
                reverse(i.begin(), i.end());
            for (auto j : i)
                a.push_back(j);
            m++;
        }

        int ret = dijkstra(1, n, a);
        cout << ret << "\n";
        
        return ret;
    }
};