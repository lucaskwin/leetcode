#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1));

        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i-1] == word2[j-1]) { // 特别注意，这里减去1
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                int minValue = min(dp[i-1][j]+1,dp[i][j-1]+1);
                dp[i][j] = min(minValue,dp[i][j]);
            }
        }
        return dp[m][n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
