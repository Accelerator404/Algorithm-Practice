#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// 蓝桥杯练习 ALGO-148 5-1最小公倍数

// 循环宏
#define _for(i, a, b) for(int i = (a); i < b;i++)

// 整数读取
long long int readint() {
    long long int tmp;
    scanf("%lld", &tmp);
    return tmp;
}

int gcd(int x,int y){
    return (y==0)?x:gcd(y,x%y);
}

int lcm(int x,int y){
    // 最小公倍数=乘积除以最大公约数
    return x*y / gcd(x,y);
}

int main() {
    int n,m;
    n = readint();
    m =readint();
    cout << lcm(n,m) << endl;
    return 0;
}
