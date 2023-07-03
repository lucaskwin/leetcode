#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> result;
    vector<int> track;
    int k;
    int target;
    int summary;
public:
    void backtrack(int start) {
        if (track.size() == k) {
            if (summary == target) {
                result.push_back(track);
            }
            return;
        }
        for (int i = start; i <= 9; ++i) {
            if (summary + i > target) {
                return;
            }
            track.push_back(i);
            summary += i;
            backtrack(i+1);
            track.pop_back();
            summary -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        this->k = k;
        this->target = n;
        backtrack(1);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
