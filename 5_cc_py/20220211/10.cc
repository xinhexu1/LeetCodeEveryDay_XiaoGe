#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (s.empty()) return count(p.begin(), p.end(), '*') * 2 >= p.length();
        else {
            bool firstMatch = (s[0] == p[0] || p[0] == '.');
            if (p[1] != '*') {
                return firstMatch && 
                    isMatch(s.substr(1, s.length()-1), p.substr(1, p.length()-1));
            } else {
                if (firstMatch) {
                    return isMatch(s.substr(1, s.length()-1), p) || 
                        isMatch(s, p.substr(2, p.length()-2));
                } else {
                    return isMatch(s, p.substr(2, p.length()-2));
                }
            }
        }
        return false;
    }
};
