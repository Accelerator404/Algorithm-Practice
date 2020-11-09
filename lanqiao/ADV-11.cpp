#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 蓝桥杯练习 ADV-11 Torry的困惑

// 循环宏
#define _for(i, a, b) for(int i = (a); i < b;i++)

// 整数读取
long long int readint() {
    long long int tmp;
    scanf("%lld", &tmp);
    return tmp;
}

#define MOD 50000

int main() {
    int N = readint();
    vector<int> v(2000000);
    // 全部标记为质数
    fill(v.begin(), v.end(), 0);
    for (int i = 2; i * i < 2000000; ++i) {
        if (v[i] == 1) {
            // 显然，任何非质数的倍数不需要判断，因为已经被其质因数的循环标记了
            continue;
        }
        for (int j = i * i; j < 2000000; j = j + i) {
            // 将所有i的i,i+1,...倍，标记为非质数
            // 之所以从i倍开始，是因为i-1,i-2的倍数已经被处理过
            v[j] = 1;
        }
        // 以上过程中逐步去掉非质数
    }
    long long int ans = 1;
    int count = 0;
    _for(i, 2, 2000000) {
        if (v[i] == 0) {
            ans = (ans * i) % MOD;
            count++;
        }
        if (count == N) {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
