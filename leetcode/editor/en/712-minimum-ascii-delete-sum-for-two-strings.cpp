#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int Min(int x,int y,int z) {
        return min(min(x,y),z);
    }
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(),n = s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));

        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i==0 && j==0){
                    dp[i][j] = 0;
                } else if (i==0){
                    dp[i][j] = dp[i][j-1] + (int)s2[j-1];
                } else if (j==0){
                    dp[i][j] = dp[i-1][j] + (int)s1[i-1];
                } else if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = Min(
                            dp[i][j-1] + (int)s2[j-1], // 删掉
                            dp[i-1][j] + (int)s1[i-1], // 新增
                            dp[i-1][j-1] + (int)s1[i-1] + (int)s2[j-1]); // 替换
                }
            }
        }
        return dp[m][n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
