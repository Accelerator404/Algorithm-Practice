#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 蓝桥杯练习 ALGO-23 一元三次方程求解

// 循环宏
#define _for(i, a, b) for(int i = (a); i < b;i++)

// 整数读取
long long int readint() {
    long long int tmp;
    scanf("%lld", &tmp);
    return tmp;
}

double a, b, c, d;

double f(double x) {
    return pow(x, 3) * a + pow(x, 2) * b + c * x + d;
}

// 要求精确度为小数点后两位
double acc_limit = 0.001;

double find(double l, double r) {
    // 递归求根
    if (abs(l - r) < acc_limit)
        return l;
    double mid = (l + r) / 2;
    double l_result = f(l);
    double r_result = f(r);
    double mid_result = f(mid);
    // 右区间
    if (l_result * mid_result > 0)
        return find(mid, r);
        // 左区间
    else
        return find(l, mid);
}

int main() {
    cin >> a >> b >> c >> d;
    // 逐个区间寻找解
    string result;
    int count = 0; // 用来控制空格数
    for (int i = -100; i <= 100; ++i) {
        // 如果边界的函数值为0，输出它
        char num[10];
        if (f(i) == 0) {
            sprintf(num, "%.2f", (double) i);
            result += num;
            count++;
            if (count < 3)
                result += " ";
        }
            // 区间内存在解
        else if (f(i) * f(i + 1) < 0) {
            sprintf(num, "%.2f", find(i, i + 1));
            result += num;
            count++;
            if (count < 3)
                result += " ";
        }
    }
    cout << result << endl;
    return 0;
}
