#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/**
 *  PKU 程序设计与算法慕课（三） C++面向对象 第一周003
 *  003:打印ASCII码
 *  描述
 *  输入一个除空格以外的可见字符（保证在函数scanf中可使用格式说明符%c读入），输出其ASCII码。
 *
 *  输入
 *  一个除空格以外的可见字符。
 *
 *  输出
 *  一个十进制整数，即该字符的ASCII码。
 */

int main(){
    char c;
    cin >> c;
    cout << (int)c;
    return 0;
}
