#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

// 蓝桥杯练习 BASIC-30 阶乘计算

// 循环宏
#define _for(i, a, b) for(int i = (a); i < b;i++)

// 整数读取
long long int readint() {
    long long int tmp;
    scanf("%lld", &tmp);
    return tmp;
}

class BigDecimal {
private:
    vector<short> a;
    vector<short> b;
public:
    BigDecimal(string a_, string b_) {
        str2short(a_, a);
        str2short(b_, b);
    }

    static void str2short(const string &s, vector<short> &d) {
        d.clear();
        _for(i, 0, s.length()) {
            d.push_back(s[i] - '0');
        }
        reverse(d.begin(), d.end());
    }

    string plus() {
        int l1 = a.size();
        int l2 = b.size();
        int lc = max(l1, l2) + 1;
        vector<short> c(lc, 0);
        // 相加
        _for(i, 0, l1) {
            c[i] += a[i];
        }
        _for(i, 0, l2) {
            c[i] += b[i];
        }
        _for(i, 0, lc - 1) {
            // 进位
            if (c[i] >= 10) {
                c[i + 1] += c[i] / 10;
                c[i] %= 10;
            }
        }
        bool flag = false;
        string res;
        // 反向输出为字符串
        for (int i = lc - 1; i >= 0; --i) {
            if (!flag and c[i] != 0) {
                flag = true;
            }
            if (flag) {
                res += (char) (c[i] + '0');
            }
        }
        return res;
    }

    string multiply() {
        int l1 = a.size();
        int l2 = b.size();
        int lc = max(l1, l2) * 2 + 1;
        vector<short> c(lc, 0);
        _for(i, 0, l1) {
            short pivot = a[i];
            _for(j, 0, l2) {
                // 逐步进行乘法计算
                c[i + j] += b[j] * pivot;
            }
            // 处理一次进位，避免出现溢出
            _for(k, 0, lc - 1) {
                if (c[k] >= 10) {
                    c[k + 1] += c[k] / 10;
                    c[k] %= 10;
                }
            }
        }
        bool flag = false;
        string res;
        // 反向输出为字符串
        for (int i = lc - 1; i >= 0; --i) {
            if (!flag and c[i] != 0) {
                flag = true;
            }
            if (flag) {
                res += (char) (c[i] + '0');
            }
        }
        return res;
    }
};

string factorial(int n) {
    // 该实现可能会因为反复在数组、串之间转换与复制，效率低
    if (n == 1)
        return "1";
    else if (n == 2)
        return "2";
    string res = "1";
    _for(i, 1, n + 1) {
        char si[5];
        sprintf(si, "%d", i);
        BigDecimal bd(res, string(si));
        res = bd.multiply();
    }
    return res;
}

int main() {
    int n = readint();
    cout << factorial(n) << endl;
    return 0;
}
