#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/**
 *  PKU 程序设计与算法慕课（三） C++面向对象 第一周006
 *  006:浮点型数据类型存储空间大小
 *  描述
 *  分别定义float，double类型的变量各一个，并依次输出它们的存储空间大小（单位：字节）。
 *
 *  输入
 *  无。
 *
 *  输出
 *  一行，两个整数，分别是两个变量的存储空间大小，用一个空格隔开。
 */

int main(){
    float a;
    double b;
    cout << sizeof(a) << ' ' << sizeof(b);
    return 0;
}
