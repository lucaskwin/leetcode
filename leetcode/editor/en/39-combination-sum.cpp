#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> result;
    vector<int> nums;
    vector<int> track;
    int target;
    int summary;
public:
    void backtrack(int start) {
        if (summary == target) {
            result.push_back(track);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            if (summary + nums[i] > target) {
                return;
            }
            track.push_back(nums[i]);
            summary += nums[i];
            backtrack(i);
            track.pop_back();
            summary -= nums[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        this->nums = candidates;
        this->target = target;
        backtrack(0);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
