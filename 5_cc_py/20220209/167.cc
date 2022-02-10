#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while (l < r) {
            int tempSum = numbers[l] + numbers[r];
            if (tempSum == target) return {l+1, r+1};
            else if (tempSum < target) ++l;
            else --r;
        }
        return {};
    }
};