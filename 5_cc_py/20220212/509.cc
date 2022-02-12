class Solution {
public:
    int fib(int n) {
        int l = 0;
        int r = 1;
        if (n == 0) return l;
        if (n == 1) return r;
        for (int i = 2; i <= n; ++i) {
            int temp = r;
            r = r+l;
            l = temp;
        }
        return r;
    }
};