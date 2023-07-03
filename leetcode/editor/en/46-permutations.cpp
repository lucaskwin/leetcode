#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> result;
    vector<int> nums;
    vector<int> track;
    vector<bool> used;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        this->nums = nums;
        backtrack();
        return result;
    }

    void backtrack() {
        if (track.size() == nums.size()) {
            result.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            track.push_back(nums[i]);
            used[i] = true;
            backtrack();
            track.pop_back();
            used[i] = false;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
