#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length() == 0)
            return "";
        if(s.length() == 1)
            return s;
        if(numRows == 1)
            return s;
        vector<string> matrix(numRows);
        unsigned count,res,ZSize;
        ZSize = numRows*2-2;
        res = s.length()%ZSize;
        count = (s.length() - res)/ZSize;
        //处理所有“规则”而完全的“z拐弯”，也就是每size=(2*numRow-2)的子串
        for (int i = 0; i < count; ++i) {
            unsigned pivot = ZSize * i;
            string Zsubstr = s.substr(pivot,ZSize);
            for (int j = 0; j < numRows; ++j) {
                matrix[j] += Zsubstr[j];
                if(j > 0 && j < numRows-1){
                    matrix[j] += Zsubstr[ZSize-j];
                }
            }
        }
        //处理最后一个不完全的“z拐弯”
        unsigned Fcount = res;
        for (int i = 0; i < numRows && Fcount > 0; ++i) {
            matrix[i] += s[s.length() - Fcount];
            Fcount--;
        }
        for (int i = numRows-2; i > 1  && Fcount > 0; --i) {
            matrix[i] += s[s.length()-Fcount];
            Fcount--;
        }
        string result;
        for (int k = 0; k < numRows; ++k) {
            result += matrix[k];
        }
        return result;
    }
};

