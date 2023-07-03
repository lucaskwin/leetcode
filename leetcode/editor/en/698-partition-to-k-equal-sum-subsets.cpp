#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> result;
    vector<int> nums;
    vector<int> track;
    vector<bool> used;
    int target = 0;
    int k = 0;
    int summary = 0;
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
            backtrack(i+1);
            track.pop_back();
            summary -= nums[i];
        }
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k > nums.size()) {
            return false;
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        if (sum % k > 0) {
            return false;
        }
        this->target = sum / k;
        sort(nums.begin(),nums.end());
        this->nums = nums;
        this->k = k;
        used = vector<bool>(nums.size(),false);
        // 回溯
        backtrack(0);
        for (int i = 0; i < result.size(); ++i) {
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        // 贪心

        return true;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
int main() {
    vector<int> v = {4,3,2,3,5,2,1};
    Solution().canPartitionKSubsets(v,4);
    return 0;
}