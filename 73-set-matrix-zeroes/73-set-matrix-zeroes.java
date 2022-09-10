class Solution 
{
    public void setZeroes(int[][] matrix) 
    {
         boolean[][] booleanCopy = new boolean[200][200];
        
        for(int i =0;i<matrix.length;i++){
            for(int j = 0;j<matrix[0].length;j++){
                
                if(matrix[i][j]==0){
                    for(int k =0;k<200;k++){
                        booleanCopy[i][k]=true;
                        booleanCopy[k][j]=true;
                    }
                    
                }
            }
        }
        
        for(int i =0;i<matrix.length;i++){
            for(int j = 0;j<matrix[0].length;j++){
                
                if(booleanCopy[i][j]) matrix[i][j]=0;
            }
        
    }
        
    }
}