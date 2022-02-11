#include <map>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        stack<map<string, int>> levelMap;
        map<string, int> curMap;
        string elem;
        int k = 0;
        int i = 0;
        while (i < n) {
            auto ch = formula[i];
            if (isalpha(ch)) {
                string at(1, ch);
                if (i+1 < n && islower(formula[i+1])) {
                    at += formula[i+1];
                    ++i;
                }
                elem = at;
                ++curMap[at];
            } else if (isdigit(ch)) {
                k = k * 10 + ch - '0';
                if ((i+1 < n && !isdigit(formula[i+1])) || i+1 == n) {
                    curMap[elem] += k-1;
                    k = 0;
                }
            } else if (ch == '(') {
                levelMap.push(curMap);
                curMap.clear();
            } else if (ch == ')') {
                while (i+1 < n && isdigit(formula[i+1])) {
                    k = k*10 + formula[i+1] - '0';
                    ++i;
                }
                k = (k > 0)? k : 1;
                map<string, int> lastLayer = levelMap.top();
                levelMap.pop();
                for (auto it = curMap.begin(); it != curMap.end(); ++it) {
                    if (lastLayer.find(it->first) != lastLayer.end()) {
                        lastLayer[it->first] += it->second * k;
                    }
                    else lastLayer[it->first] = it->second * k;
                }
                k = 0;
                curMap = lastLayer;
            }
            ++i;
        }
        string rst;
        for (auto it = curMap.begin(); it != curMap.end(); ++it) {
            string tailNum = (it->second > 1)? to_string(it->second) : "";
            rst += it->first + tailNum;
        }
        return rst;
    }
};