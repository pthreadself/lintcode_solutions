/*
        Given three strings: s1, s2, s3, determine whether s3
        is formed by the interleaving of s1 and s2.
        Example
        For s1 = "aabcc", s2 = "dbbca"

        When s3 = "aadbbcbcac", return true.
        When s3 = "aadbbbaccc", return false.

        code by wang.ke

*/
class Solution {
public:
    /**
    * Determine whether s3 is formed by interleaving of s1 and s2.
    * @param s1, s2, s3: As description.
    * @return: true of false.
    */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();

        if (len1 + len2 != len3)
            return false;

        vector<bool> row(len2 + 1, true);
        vector<vector<bool>> dp(len1 + 1, row);


        for (int j = 1; j <= len2; j++)
            if ((s2[j - 1] == s3[j - 1]))
                dp[0][j] = dp[0][j - 1];
            else
                dp[0][j] = false;

        for (int i = 1; i <= len1; i++)
            if (s1[i - 1] == s3[i - 1])
                dp[i][0] = dp[i - 1][0];
            else
                dp[i][0] = false;

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) {
                    dp[i][j] = true;
                    continue;
                }
                if (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]) {
                    dp[i][j] = true;
                    continue;
                }
                dp[i][j] = false;
            }
        }

        return dp[len1][len2];
    }
};
