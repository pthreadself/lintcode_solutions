/*
http://www.lintcode.com/en/problem/minimum-adjustment-cost/

Given an integer array, adjust each integers so that the difference of every adjacent integers are not greater than a given number target.

If the array before adjustment is A, the array after adjustment is B, you should minimize the sum of |A[i]-B[i]|

Example
Given [1,4,2,3] and target = 1, one of the solutions is [2,3,2,3], the adjustment cost is 2 and it's minimal.

Return 2.

Note
You can assume each number in the array is a positive integer and not greater than 100


*/

//by wang.ke
class Solution {
public:
    /**
    * @param A: An integer array.
    * @param target: An integer.
    */
    int MinAdjustmentCost(vector<int> a, int target) {
        // write your code here
        int size = a.size();
        if (size == 1)
            return 0;
        vector<vector<int>> dp(size, vector<int>(101, INT_MAX));
        for (int j = 0; j <= 100; ++j) {
            dp[0][j] = abs(j - a[0]);
        }

        for (int i = 1; i < size; ++i) {
            for (int j = 0; j <= 100; ++j) {
                int low_boundary = max(0, j - target);
                int high_boundary = min(j + target, 100);
                for (int k = low_boundary; k <= high_boundary; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(a[i] - j));
                }
            }
        }
    
        int opt = INT_MAX;
        for (int i = 0; i <= 100; ++i) {
            opt = min(opt, dp[size - 1][i]);
        }

        return opt;
    }
};