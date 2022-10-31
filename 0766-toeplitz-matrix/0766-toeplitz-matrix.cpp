class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int k=0;
        while(k<m || k<n){
            int i=1,j=1;
            while(i+k<m && j<n){
                if(matrix[i+k][j]!=matrix[i+k-1][j-1])return false;
                i++,j++;
            }
            i=1,j=1;
            while(i<m && j+k<n){
                if(matrix[i][j+k]!=matrix[i-1][j+k-1])return false;
                i++,j++;
            }
            k++;
        }
        return true;
    }
};