#include <bits/stdc++.h>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> result;
    vector<int> track;
    int target;
    int k;
public:
    void backtrack(int start){
        if(track.size() == k) {
            result.push_back(track);
            return;
        }
        for (int i = start; i <= target; ++i) {
            track.push_back(i);
            backtrack(i+1);
            track.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        this->target = n;
        this->k = k;
        backtrack(1);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
