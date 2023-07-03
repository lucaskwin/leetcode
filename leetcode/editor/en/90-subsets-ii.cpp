#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> result;
    vector<int> nums;
    vector<int> track;
public:
    void backtrack(int start) {
        result.push_back(track);
        for (int i = start; i < nums.size(); ++i) {
            if(i > start && nums[i] == nums[i-1]) {
                continue;
            }
            track.push_back(nums[i]);
            backtrack(i+1);
            track.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        this->nums = nums;
        backtrack(0);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
