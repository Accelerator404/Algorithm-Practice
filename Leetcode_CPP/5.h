#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1)
            return s;
        string LPS;
        str_plot u;
        vector<str_plot> PS_pool;
        //先筛选出所有长度为2、3的回文串
        for (int i = 0; i < s.length()-1; ++i) {
            u.pivot = i;
            u.length = 2;
            if(s[i]==s[i+1])
                PS_pool.push_back(u);
        }
        for (int i = 0; i < s.length()-2; ++i) {
            u.pivot = i;
            u.length = 3;
            if(s[i]==s[i+2])
                PS_pool.push_back(u);
        }
        //不存在回文串则返回首字符
        if(PS_pool.empty())
            return s.substr(0,1);
        //对每个短回文串，向两侧同时延长，直到延长后的子串不是回文串
        for (auto it = PS_pool.begin(); it != PS_pool.end(); ++it) {
            ExtendPS(s,*it);
        }
        //选出最长的回文串
        for (auto it = PS_pool.begin(); it != PS_pool.end(); ++it) {
            if(it->length > LPS.length()){
                LPS = s.substr(it->pivot,it->length);
            }
        }
        return LPS;
    }
    //用开始位置&长度表示一个子字符串
    struct str_plot{
        unsigned short pivot,length;
    };
    inline void ExtendPS(const string & s,str_plot & basicSTR){
        while(true){
            short leftVal = basicSTR.pivot - 1;
            unsigned short rightVal = basicSTR.length+basicSTR.pivot;
            // 检查越界
            if(leftVal < 0 || (rightVal > s.length()-1))
                break;
            else if(s[leftVal] == s[rightVal]){
                basicSTR.pivot--;
                basicSTR.length += 2;
            }
            else
                break;
        }
    }
};

