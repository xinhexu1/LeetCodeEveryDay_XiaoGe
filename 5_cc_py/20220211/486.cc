#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp (n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }
        for (int i = 0; i < n-1; ++i) {
            dp[i][i+1] = max(nums[i], nums[i+1]);
        }
        for (int k = 2; k < n; ++k) {
            for (int i = 0; i < n-k; ++i) {
                dp[i][i+k] = max(nums[i] + min(dp[i+1][i+k-1], dp[i+2][i+k]),
                                nums[i+k] + min(dp[i][i+k-2], dp[i+1][i+k-1]));
            }
        }
        int total = accumulate(nums.begin(), nums.end(), 0);
        return dp[0][n-1] * 2 >= total;
    }
};