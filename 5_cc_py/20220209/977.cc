#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> rst;
        int l = 0, r = nums.size()-1;
        while (nums[l] * nums[r] <= 0 && l < r) {
            if (abs(nums[l]) >= abs(nums[r])) {
                rst.push_back(pow(nums[l], 2));
                ++l;
            } else {
                rst.push_back(pow(nums[r], 2));
                --r;
            }
        }
        if (nums[l] > 0) {
            while (r > l) {
                rst.push_back(pow(nums[r], 2));
                --r;
            }
        } else {
            while (r > l) {
                rst.push_back(pow(nums[l], 2));
                ++l;
            }
        }
        rst.push_back(pow(nums[l], 2));
        reverse(rst.begin(), rst.end());
        return rst;
    }
};