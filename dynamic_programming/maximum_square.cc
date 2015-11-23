
/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4.
*/

//by wang.ke

class Solution {
public:
    /**
    * @param matrix: a matrix of 0 and 1
    * @return: an integer
    */
    int maxSquare(vector<vector<int> > &matrix) {
        // write your code here
        int rows = matrix.size();
        if (rows == 0)
            return 0;
        int cols = matrix[0].size();
        if (cols == 0)
            return 0;

        vector<vector<int>> dp(rows, vector<int>(cols,0));
        for (int i = 0; i < cols; i++) 
            dp[0][i] = matrix[0][i] == 1 ? 1 : 0;

        for (int i = 1; i < rows; i++)
            dp[i][0] = matrix[i][0] == 1 ? 1 : 0;

        int dpmax = matrix[0][0];
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                int edge = dp[i - 1][j - 1];
                int left = dp[i][j - 1];
                int up = dp[i - 1][j];
                if (left >= edge &&
                    up >= edge && 
                    matrix[i][j] == 1) {
                    dp[i][j] = edge + 1;
                }
                else {
                    dp[i][j] = matrix[i][j] == 0 ? 0 : 1 + min(left, up);
                }

                if (dp[i][j] > dpmax) {
                    dpmax = dp[i][j];
                }
            }
        }
        return dpmax * dpmax;
    }
};