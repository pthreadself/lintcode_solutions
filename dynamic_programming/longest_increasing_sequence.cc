/*
Given a sequence of integers, find the longest increasing subsequence (LIS).

You code should return the length of the LIS.

Have you met this question in a real interview? Yes
Example
For [5, 4, 1, 2, 3], the LIS  is [1, 2, 3], return 3

For [4, 2, 4, 5, 3, 7], the LIS is [4, 4, 5, 7], return 4

Challenge
Time complexity O(n^2) or O(nlogn)

*/
//code by wang.ke
class Solution {
public:
    /**
    * @param nums: The integer array
    * @return: The length of LIS (longest increasing subsequence)
    */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        int size = nums.size();
        if (size == 0)
            return 0;
        vector<int> dp(size, 1);
        int dpmax = 1;
        for (int i = 1; i < size; i++) {
            int tmpmax = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] >= nums[j] && dp[j] >= tmpmax) {
                    dp[i] = dp[j] + 1;
                    tmpmax = dp[j];
                }
            }
            if (dp[i] > dpmax)
                dpmax = dp[i];
        }

        return dpmax;
    }
};