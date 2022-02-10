#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int curMax = 0;
        while (l < r) {
            int lh = height[l], rh = height[r];
            if (lh >= rh) curMax = max(curMax, rh * ((r--)-l));
            else curMax = max(curMax, lh * (r-(l++)));
        }
        return curMax;
    }
};