#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int findRotateSteps(string ring, string key) {
        unordered_map<char,vector<int>> charIndex;
        for (int i = 0; i < ring.size(); i++) {
            charIndex[ring[i]].push_back(i);
        }
        const int m = ring.size();
        const int n = key.size();
        int** dp = new int*[m];
        for (int i = 0; i < m; ++i) {
            dp[i] = new int[n];
            for (int j = 0; j < n; ++j) {
                dp[i][j] = m*n;
            }
        }
        //vector<vector<int>> dp(m,vector<int>(target,m*target));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                for (int k : charIndex[key[j]]) {
                    int absValue = abs(k-i);
                    int minValue = min(absValue,m-absValue);
                    if(j==0) {
                        dp[i][j] = min(dp[i][j],minValue + 1);
                    } else {
                        dp[i][j] = min(dp[i][j],dp[k][j-1] + minValue + 1);
                    }
                }
            }
        }
        int result = m*n;
        for (int i = 0; i < m; ++i) {
            result = min(result,dp[i][n-1]);
        }

        for (int i = 0; i < m; i++) {
            delete[] dp[i];
        }
        delete[] dp;
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main(){
    cout << Solution().findRotateSteps("edcba","abcde");
    return 0;
}