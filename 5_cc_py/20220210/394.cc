#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> cs;
        stack<string> ss;
        string curS;
        int k = 0;
        for (auto ch : s) {
            if (isdigit(ch)) k = k*10 + ch - '0';
            else if (isalpha(ch)) curS += ch;
            else if (ch == '[') {
                cs.push(k);
                ss.push(curS);
                k = 0;
                curS = "";
            }
            else {
                string lastLayer = ss.top();
                int mult = cs.top();
                ss.pop();
                cs.pop();
                for (int i = 0; i < mult; ++i) {
                    lastLayer += curS;
                }
                curS = lastLayer;
            }
        }
        return curS;
    }
};