class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return (ValidBoxes(board) && ValidCols(board) && ValidRows(board));

    }
    //CHECK COLS
    bool ValidCols(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.')
                for(int k=j+1;k<board[0].size();k++){
                    if(board[i][j]==board[i][k])
                       return false;
                }
            }
    return true;
    }
     //CHECK ROWS
     bool ValidRows(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++){
                if(board[j][i]!='.')
                for(int k=j+1;k<board[0].size();k++){
                    if(board[j][i]==board[k][i])
                    {
                        return false;
                    }
                }
            }
    return true;
    }
    //CHECK SUBOXES
    bool ValidBoxes(vector<vector<char>>& board)
    {
    for(int row = 0; row < 9; row = row + 3){
        for(int col = 0; col < 9; col = col + 3){
        set<int> s;
            for(int r = row; r < row + 3; r++){
                for(int c = col; c < col + 3; c++){
                    if(board[r][c]!='.'){
                        if(s.insert(board[r][c]).second == false){
                            return false;
                }
              } 
            }
          }
        }    
    }
 return true; 
    }
};