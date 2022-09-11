class Solution 
{
    public boolean exist(char[][] board, String word) 
    {
        // public boolean exist(char[][] board, String word) {
    int idxChar = 0;
    boolean[][] isVisited = new boolean[board.length][board[0].length];
    
    for ( int i = 0; i < board.length ; i++) {
        for ( int j = 0; j < board[0].length ; j++) {
            if (board[i][j] == word.charAt(idxChar)) {
               if (dfs(i, j, board, isVisited, word, idxChar) == true)
                   return true;
            }
        }
    }
    return false;
}


boolean dfs(int row, int col,char[][] board, boolean[][] isVisited, String word, int idx) {
    if (row >= 0 && row < isVisited.length && col >= 0 && col < isVisited[0].length && !isVisited[row][col] && word.charAt(idx) == board[row][col]){
        if (idx == word.length() - 1) return true;
        isVisited[row][col] = true;
        idx++;
        boolean right = dfs(row, col + 1, board, isVisited, word, idx);
        boolean left = dfs(row, col - 1, board, isVisited, word, idx);
        boolean up = dfs(row + 1, col, board, isVisited, word, idx);
        boolean down = dfs(row - 1, col, board, isVisited, word, idx);
        boolean isFound = right || left || up || down;
        isVisited[row][col] = isFound;
        return isFound;
    }
    else return false;

        
    }
}