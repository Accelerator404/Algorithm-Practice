#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/**
 *  PKU 程序设计与算法慕课（三） C++面向对象 第一周005
 *  005:整型数据类型存储空间大小
 *  描述
 *  输入一个ASCII码，输出对应的字符。
 *
 *  输入
 *  无。
 *
 *  输出
 *  一行，两个整数，分别是两个变量的存储空间大小，用一个空格隔开。
 */

int main(){
    int a;
    short b;
    cout << sizeof(a) << ' ' << sizeof(b);
    return 0;
}
