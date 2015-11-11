/*
There are n coins with different value in a line. 
Two players take turns to take one or two coins from left side until there are no more coins left. 
The player who take the coins with the most value wins.
Could you please decide the first player will win or lose?

Example
Given values array A = [1,2,2], return true.
Given A = [1,2,4], return false.
*/

//by wang.ke
class Solution {
public:
    /**
    * @param values: a vector of integers
    * @return: a boolean which equals to true if the first player will win
    */
    bool firstWillWin(vector<int> &values) {
        int n = values.size();
        values.push_back(0);
        vector<int> opt(n + 4, 0);

        int sum = 0;
        for (auto & e : values)
            sum += e;

        for (int i = n - 1; i >= 0; i--) {
            int a = values[i] + opt[i + 3];
            int b = values[i] + opt[i + 2];
            int c = values[i] + values[i + 1] + opt[i + 3];
            int d = values[i] + values[i + 1] + opt[i + 4];

            //must choose the smaller one between a and b
            //because the opponent may choose whatever strategy he likes
            int smaller1 = min(a, b);

            //must choose the smaller one between a and b
            //because the opponent may choose whatever strategy he likes
            int smaller2 = min(c, d);

            //must choose the greater one between smaller1 and smaller2
            //because given the opponent's strategy, we choose the optimal one for ourselves
            opt[i] = max(smaller1, smaller2);
        }

        int opponent = sum - opt[0];
        return (opt[0] > opponent);
    }
};

