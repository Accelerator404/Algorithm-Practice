#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 蓝桥杯练习 ADV-12 计算时间

// 循环宏
#define _for(i, a, b) for(int i = (a); i < b;i++)

// 整数读取
long long int readint() {
    long long int tmp;
    scanf("%lld", &tmp);
    return tmp;
}

int main() {
    int T = readint();
    _for(i,0,T){
        int t = readint();
        int hour = t/3600;
        int minute = (t%3600)/60;
        int second = t%60;
        printf("%02d:%02d:%02d\n",hour,minute,second);
    }
    return 0;
}
