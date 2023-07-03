#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m,vector<int>(n,1000*401));
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                if(i == m-1 && j == n-1) {
                    dp[i][j] = dungeon[i][j] >= 0 ? 1 : 1 - dungeon[i][j];
                } else if (i == m-1) {
                    dp[i][j] = dp[i][j+1] - dungeon[i][j];
                } else if (j == n-1) {
                    dp[i][j] = dp[i+1][j] - dungeon[i][j];
                } else {
                    dp[i][j] = min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j];
                }
                dp[i][j] = dp[i][j] <= 0 ? 1 : dp[i][j];
            }
        }
        return dp[0][0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main()
{

    vector<vector<int>> dungeon = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    cout << Solution().calculateMinimumHP(dungeon);

    return 0;
}