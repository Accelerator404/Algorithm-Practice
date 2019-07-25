#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        string p = to_string(x);
        // 负号
        if(p[0] == '-')
            std::reverse(p.begin()+1,p.end());
        else
            std::reverse(p.begin(),p.end());
        long long int xr = stoll(p);
        // 溢出
        if(xr > INT32_MAX || xr < INT32_MIN)
            return 0;
        return (int)xr;
    }
};

