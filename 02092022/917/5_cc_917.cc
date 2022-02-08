#include <string>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l = 0, r = s.length()-1;
        while (l < r) {
            while (l < r && !isalpha(s[l])) ++l;
            while (l < r && !isalpha(s[r])) --r;
            if (l == r) return s;
            swap(s[l++], s[r--]);
        }
        return s;
    }
};