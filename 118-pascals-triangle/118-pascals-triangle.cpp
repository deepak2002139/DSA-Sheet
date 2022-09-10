class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
    vector < vector < int >> x(numRows);

  for (int i = 0; i < numRows; i++) 
  {

    x[i].resize(i + 1);
    x[i][0] = 1;
    x[i][i] = 1;

    for (int j = 1; j < i; j++) {

      x[i][j] = x[i - 1][j - 1] + x[i - 1][j];

    }

  }
  return x;

}
};
