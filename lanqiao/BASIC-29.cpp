#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 蓝桥杯练习 BASIC-29 高精度加法

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
};

int main() {
    string a, b;
    cin >> a >> b;
    BigDecimal bd(a, b);
    cout << bd.plus() << endl;
    return 0;
}
