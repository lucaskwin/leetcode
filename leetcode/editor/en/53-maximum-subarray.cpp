#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0],dp_0 = nums[0],dp_1 = 0;
        for (int i = 1; i < nums.size(); ++i) {
            dp_1 = max(dp_0+nums[i],nums[i]);
            dp_0 = dp_1;
            result = max(result,dp_1);
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> v(a,a+9);
    cout << Solution().maxSubArray(v) <<endl;
    return 0;
}