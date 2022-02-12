#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string single(int num) {
        unordered_map<int, string> mapp {{1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"},
                                         {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"},
                                         {9, "Nine"}
                                        };
        return mapp[num];
    }
    
    string tenToNineteen(int num) {
        unordered_map<int, string> mapp {{10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, 
                                         {13, "Thirteen"}, {14, "Fourteen"},
                                         {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, 
                                         {18, "Eighteen"}, {19, "Nineteen"}
                                        };
        return mapp[num];
    }
    
    string tens(int num) {
        unordered_map<int, string> mapp {{2, "Twenty"}, {3, "Thirty"}, {4, "Forty"},
                                         {5, "Fifty"}, {6, "Sixty"}, {7, "Seventy"},
                                         {8, "Eighty"},{9, "Ninety"}
                                        };
        return mapp[num];
    }
    
    string twoDigit(int num) {
        if (num == 0) return "";
        else if (num < 10) return single(num);
        else if (num < 20) return tenToNineteen(num);
        else {
            int ten = num / 10;
            int res = num % 10;
            if (res == 0) return tens(ten);
            return tens(ten) + " " + single(res);
        }
    }
    
    string threeDigit(int num) {
        int hund = num / 100;
        int res = num % 100;
        if (hund == 0) {
            return twoDigit(res);
        }
        else {
            if (res == 0) return single(hund) + " Hundred";
            return single(hund) + " Hundred " + twoDigit(res);
        }
    }
    
    string numberToWords(int num) {
        int bil = num / 1000000000;
        int mil = (num - bil * 1000000000) / 1000000;
        int thou = (num - bil * 1000000000 - mil * 1000000) / 1000;
        int res = num - bil * 1000000000 - mil * 1000000 - thou * 1000;
        if (num == 0) return "Zero";
        string rst = "";
        if (bil != 0) rst += threeDigit(bil) + " Billion";
        if (mil != 0) rst += ' ' + threeDigit(mil) + " Million";
        if (thou != 0) rst += ' ' + threeDigit(thou) + " Thousand";
        if (res) rst += ' ' + threeDigit(res);
        if (rst[0] == ' ') rst = rst.substr(1, rst.length()-1);
        if (rst[rst.length()-1] == ' ') rst = rst.substr(0, rst.length()-1);
        return rst;
    }
};