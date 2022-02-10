#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = nums.size() - 2;
        while (ind >= 0 && nums[ind+1] <= nums[ind]) --ind;
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int swapInd = ind+1;
        while (swapInd < nums.size() && nums[swapInd] > nums[ind]) ++swapInd;
        swapInd = (swapInd == nums.size())? nums.size()-1 : swapInd-1;
        swap(nums[ind], nums[swapInd]);
        reverse(nums.begin()+ind+1, nums.end());
    }
};