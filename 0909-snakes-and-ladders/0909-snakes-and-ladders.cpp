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
    int snakesAndLadders(vector<vector<int>>& board) {
        int N = board.size();
        vector<int> list(N * N);
        vector<int> mins(N * N, -1);
        int i, j;
        for(i = 0; i < N; ++i) {
            for(j = 0; j < N; ++j) {
                if(i % 2 == 0) list[i * N + j] = board[N - 1 - i][j] - 1;
                else list[i * N + N - j - 1] = board[N - 1 - i][j] - 1;
            }
        }
        recur(list, mins, 0, 0, N * N - 1);
        return mins[N * N - 1];
    }
    
    void recur(vector<int> &board, vector<int> &mins, int cur, int cur_s, int M) {
        if(mins[cur] != -1 && mins[cur] <= cur_s) return; 
        if(mins[cur] == -1 || cur_s < mins[cur]) mins[cur] = cur_s;
        if(cur == M) return;
        for(int i = cur + 1; i <= cur + 6 && i <= M; ++i) {
            if(board[i] >= 0) recur(board, mins, board[i], cur_s + 1, M);
            else recur(board, mins, i, cur_s + 1, M);
        }
        return;
    }
};