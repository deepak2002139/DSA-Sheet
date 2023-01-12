class Solution 
{
public:
    vector<vector<string>> solutions;

    // check current board is valid or not
    bool is_valid(vector<string>& board, int cur_row, int cur_col, int board_size)
    {
        // col
        for(int i = 1; i <= cur_row; ++i)
        {
            if(board[i - 1][cur_col]=='Q')
                return false;
            if(cur_col - i >= 0 && board[cur_row - i][cur_col - i]=='Q')
                return false;
            if(cur_col + i < board_size && board[cur_row - i][cur_col + i]=='Q')
                return false;
        }
        return true;
    }

    // backtrack all the possibilities of the board
    void backtrack(vector<string>& board, int cur_row, int board_size)
    {
        // if reach the last row, add solution, end backtrack
        if(cur_row >= board_size)
        {
            solutions.push_back(board);
            return;
        }
        // try out every possibility
        for(int i = 0; i < board_size; ++i)
        {
            board[cur_row][i] = 'Q';
            if(is_valid(board, cur_row, i, board_size))
            {
                backtrack(board, cur_row+1, board_size);
            }
            board[cur_row][i] = '.';
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string>board(n,string(n,'.'));
        backtrack(board,0,n);
        return solutions;
    }
};