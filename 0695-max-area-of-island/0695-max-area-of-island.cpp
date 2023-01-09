class Solution {
public:
 void bfs(vector<vector<int>>& grid , vector<vector<int>>& vis , int r , int c ,
    int rowSize , int colSize){
        queue<pair<int , int>> q;
        q.push({r , c});
        vis[r][c] = 1;
        int temp = 1;
        int max_area=INT_MIN;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            if(row - 1 >= 0 && grid[row-1][col] == 1 && vis[row-1][col] == -1){
                q.push({row - 1 , col});
                vis[row-1][col] = 1;
                temp++;
            }
            
            if(col - 1 >= 0 && grid[row][col-1] == 1 && vis[row][col-1] == -1){
                q.push({row , col - 1});
                vis[row][col-1] = 1;
                temp++;
            }
            
            if(row + 1 < rowSize && grid[row+1][col] == 1 && vis[row+1][col] == -1){
                q.push({row + 1 , col});
                vis[row+1][col] = 1;
                temp++;
            }
            
            if(col + 1 < colSize && grid[row][col + 1] == 1 && vis[row][col + 1] == -1){
                q.push({row , col + 1});
                vis[row][col + 1] = 1;
                temp++;
            }
            
            if(row - 1 >= 0 && col - 1 >= 0 && grid[row-1][col-1] == 1 && vis[row-1][col-1] == -1){
                q.push({row - 1 , col - 1});
                vis[row-1][col-1] = 1;
                temp++;
            }
            
            if(row - 1 >= 0 && col + 1 < colSize && grid[row-1][col + 1] == 1 && vis[row-1][col + 1] == -1){
                q.push({row - 1 , col + 1});
                vis[row-1][col+1] = 1;
                temp++;
            }
            
            if(row + 1 < rowSize && col + 1 < colSize && grid[row+1][col+1] == 1 && vis[row+1][col+1] == -1){
                q.push({row + 1 , col + 1});
                vis[row+1][col+1] = 1;
                temp++;
            }
            
            if(row + 1 < rowSize && col - 1 >= 0 && grid[row+1][col-1] == 1 && vis[row+1][col-1] == -1){
                q.push({row + 1 , col-1});
                vis[row+1][col-1] = 1;
                temp++;
            }
        }
        max_area = max(max_area , temp);
    }
    
    int dfs(vector<vector<int>>& grid , vector<vector<int>>& vis , int row , int col ,
    int rowSize , int colSize){
        if(row < 0 || col < 0 || row >= rowSize || col >= colSize || grid[row][col] == 0 || vis[row][col] != -1){
            return 0;
        }else{
            vis[row][col] = 1;
            return 1 + dfs(grid , vis , row - 1 , col , rowSize , colSize) + 
            dfs(grid , vis , row + 1 , col , rowSize , colSize) + 
            dfs(grid , vis , row , col - 1 , rowSize , colSize) + 
            dfs(grid , vis , row , col + 1 , rowSize , colSize) ; 
            // dfs(grid , vis , row - 1 , col - 1 , rowSize , colSize) +
            // dfs(grid , vis , row - 1 , col + 1 , rowSize , colSize) +
            // dfs(grid , vis , row + 1 , col - 1 , rowSize , colSize) +
            // dfs(grid , vis , row + 1 , col + 1 , rowSize , colSize);
        }
    }
    
    
    //Function to find unit area of the largest region of 1s.
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n , vector<int> (m , -1));
        
        int area = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] == -1 && grid[i][j] == 1){
                    //bfs(grid , vis , i , j , n , m);
                    area = max(area , dfs(grid , vis , i , j , n , m));
                }
            }
        }
        //return max_area
        return area;

    }
};
