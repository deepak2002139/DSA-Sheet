class Solution {
public:

    const vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1},{0, 1}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        pair<int, int> s = {entrance[0], entrance[1]};

        auto at_exit = [&m, &n](const pair<int, int> & x) {
            return x.first == 0 || x.first == m - 1 || x.second == 0 || x.second == n - 1;
        };

        maze[s.first][s.second] = 'x';

        q.push(s);
        int steps = 0;
        while (! q.empty())
        {
            int sz = q.size();
            steps ++;
            while (sz > 0)
            {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : dir)
                {
                    int nx = x + dx, ny = y + dy;
                    if (0 <= nx && nx < m && 0 <= ny && ny < n && maze[nx][ny] == '.')
                    {
                        pair<int, int> ns = {nx, ny};
                        maze[nx][ny] = 'x';
                        if (at_exit(ns))
                        {
                            return steps;
                        }
                        q.push(ns);
                    }
                }
                sz --;
            }
        }

        return -1;
    }
};