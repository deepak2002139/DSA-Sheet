class Solution {
    int dynamic_programming(vector<vector<int>>& scores) {
        int width = scores[0].size();
        int height = scores.size();

        vector<int>& prev_scores_row = scores[0];
        for (int j{ 1 }; j < height; ++j) {
            vector<int>& scores_row = scores[j];
            vector<int>::iterator prev_scores_row_begin = prev_scores_row.begin();
            for (int i{ 0 }; i < width; ++i) {
                scores_row[i] += *min_element(prev_scores_row_begin + max(i - 1, 0), prev_scores_row_begin + min(i + 2, width));
            }
            prev_scores_row = scores_row;
        }
        return *min_element(prev_scores_row.begin(), prev_scores_row.end());
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        return this->dynamic_programming(matrix);
    }
};