#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// 蓝桥杯练习 ALGO-86 矩阵乘法

// 循环宏
#define _for(i, a, b) for(int i = (a); i < b;i++)

// 整数读取
long long int readint() {
    long long int tmp;
    scanf("%lld", &tmp);
    return tmp;
}

int main() {
    int m, s, n;
    cin >> m >> s >> n;
    int A[200][200];
    int B[200][200];
    _for(i, 0, m) {
        _for(j, 0, s) {
            A[i][j] = readint();
        }
    }
    _for(i, 0, s) {
        _for(j, 0, n) {
            B[i][j] = readint();
        }
    }
    _for(i, 0, m) {
        _for(j, 0, n) {
            int sum = 0;
            _for(k, 0, s) {
                sum += A[i][k] * B[k][j];
            }
            printf("%d", sum);
            if (j < n - 1)
                printf(" ");
            else
                printf("\n");
        }
    }
    return 0;
}
