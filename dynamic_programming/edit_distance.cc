/*
    Given two words word1 and word2, find the minimum number of steps required
    to convert word1 to word2. (each operation is counted as 1 step.)

    You have the following 3 operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character


*/

class Solution {
public:
    /**
    * @param word1 & word2: Two string.
    * @return: The minimum number of steps.
    */
    int minDistance(string word1, string word2) {
        // write your code here
        const int costr = 1; //cost of replace
        const int costi = 1; //cost of insert
        const int costd = 1; //cost of delete
        int leni = word1.length();
        int lenj = word2.length();

        if (leni == 0)
            return (lenj)*costi;
        if (lenj == 0)
            return (leni)*costi;

        vector<int> row(lenj+1, 0);
        vector<vector<int>> vv(leni+1, row);

        for (int j = 0; j <= lenj - 1; j++) {
            vv[leni][j] = costi*(lenj -j);
        }

        for (int i = 0; i <= leni - 1; i++) {
            vv[i][lenj] = costd*(leni -i);
        }

        vv[leni][lenj] = 0;

        for (int i = leni - 1; i >= 0; i--) {
            for (int j = lenj - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    vv[i][j] = vv[i + 1][j + 1];
                }
                else {
                    int a = costr + vv[i + 1][j + 1];
                    int b = costi + vv[i][j + 1];
                    int c = costd + vv[i + 1][j];
                    int smaller = min(a, b);
                    smaller = min(smaller, c);
                    vv[i][j] = smaller;
                }
            }
        }
        return vv[0][0];
    }
};
