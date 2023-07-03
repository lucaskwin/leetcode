#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> result;
    vector<int> track;
    vector<int> nums;
    vector<bool> used;
public:
    void backtrack() {
        if (track.size() == nums.size()) {
            result.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            if (i!=0 && nums[i] == nums[i-1] && !used[i-1]) {
                continue;
            }
            track.push_back(nums[i]);
            used[i] = true;
            backtrack();
            track.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        this->nums = nums;
        used = vector<bool>(nums.size(),false);
        backtrack();
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
