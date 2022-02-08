#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string cleanString = "";
        for (auto ch : s) {
            if (isalnum(ch)) cleanString += tolower(ch);
        }
        int n = cleanString.length();
        for (int i = 0; i < n/2; ++i) {
            if (cleanString[i] != cleanString[n-i-1]) return false;
        }
        return true;
    }
};