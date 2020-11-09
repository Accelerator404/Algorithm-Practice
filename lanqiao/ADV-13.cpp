#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 蓝桥杯练习 ADV-13 最小乘积

// 循环宏
#define _for(i, a, b) for(int i = (a); i < b;i++)

// 整数读取
long long int readint() {
    long long int tmp;
    scanf("%lld", &tmp);
    return tmp;
}

void read_ints(vector<int> &a, int n) {
    if (a.size() < n) {
        a.resize(n);
    }
    _for(i, 0, n) {
        a[i] = readint();
    }
}

int main() {
    int T, n;
    vector<int> x1, x2;
    T = readint();
    _for(i, 0, T) {
        n = readint();
        read_ints(x1, n);
        read_ints(x2, n);
        // 显然，我们假定数据可以被排序为{1,2,3...n}的形式，那么对于两个这样的数组
        // x1的最大值与x2的最小值相乘时值最小，之后对子数列递归，便可保证最小
        // 特别是当数组同时包括正数与负数时，尽可能保证负数与正数相乘时总乘积最小
        // 那么只需要将两个数组分别排序，一个升序，一个降序即可
        sort(x1.begin(), x1.end(), greater<>());
        sort(x2.begin(), x2.end(), less<>());
        // 按位相乘后相加
        int sum = 0;
        _for(j, 0, n) {
            sum += x1[j] * x2[j];
        }
        cout << sum << endl;
    }
    return 0;
}
