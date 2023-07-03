#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<int> track;
    vector<vector<int>> result;
    vector<int> nums;
public:
    void backtrack(int start){
        result.push_back(track);
        for (int i = start; i < nums.size(); ++i) {
            track.push_back(nums[i]);
            backtrack(i+1);
            track.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        backtrack(0);
        return result;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
