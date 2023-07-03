#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> result;
    vector<int> track;
    vector<int> nums;
    int summary;
    int target;
public:
    void backtrack(int start) {
        if (summary == target) {
            result.push_back(track);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i-1]) {
                continue;
            }
            if (summary + nums[i] > target) {
                continue;
            }
            track.push_back(nums[i]);
            summary += nums[i];
            backtrack(i+1);
            track.pop_back();
            summary -= nums[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        nums = candidates;
        this->target = target;
        backtrack(0);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
