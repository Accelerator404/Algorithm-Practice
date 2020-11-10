#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 蓝桥杯练习 BASIC-21 Sine之舞

// 循环宏
#define _for(i, a, b) for(int i = (a); i < b;i++)

// 整数读取
long long int readint() {
    long long int tmp;
    scanf("%lld", &tmp);
    return tmp;
}


int main() {
    int N = readint();
    string An[202];
    string s;
    // 叠加每个表达式的前缀
    An[0] = "sin(1"; // 而An[0]对应的是A1
    _for(i, 1, N) {
        An[i] = An[i - 1];
        // 按奇偶处理加减号
        if (i % 2 == 1) {
            An[i] += "-";
        } else {
            An[i] += "+";
        }
        An[i] += "sin(";
        char num[4];
        sprintf(num, "%d", i + 1); // 注意此处是i+1
        An[i] += num;
    }
    // 加上每个表达式的尾部括号
    _for(i, 0, N) {
        _for(j, 0, i + 1) {
            An[i] += ")";
        }
    }
    // 生成Sn
    // 从A2~An各对应一组括号
    _for(i, 2, N + 1) {
        s += "(";
    }
    // 以每一组中(...)An+k)..,k=N+1-n计算
    for (int i = N - 1; i >= 1; --i) {
        s += An[N - i - 1];
        s += "+";
        char num[4];
        sprintf(num, "%d", i + 1);
        s += num;
        s += ")";
    }
    // 加上An
    s += An[N - 1];
    s += "+1";
    cout << s;
    return 0;
}
