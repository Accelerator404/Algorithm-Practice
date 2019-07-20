#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/**
 *  PKU 程序设计与算法慕课（一） C++面向对象 第一周004
 *  004:打印字符
 *  描述
 *  输入一个ASCII码，输出对应的字符。
 *
 *  输入
 *  一个整数，即字符的ASCII码，保证存在对应的可见字符。
 *
 *  输出
 *  一行，包含相应的字符。
 */

int main(){
    int c;
    cin >> c;
    cout << (char)c;
    return 0;
}
