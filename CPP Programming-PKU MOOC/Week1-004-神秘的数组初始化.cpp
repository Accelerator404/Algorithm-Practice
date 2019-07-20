#include <iostream>
#include <cstdio>

using namespace std;

/**
 *  PKU 程序设计与算法慕课（三） C++面向对象 第一周004
 *  004:神秘的数组初始化
 *  描述
 *  填空，使得程序输出指定结果
 *
 *  输入
 *  无。
 *
 *  输出
 *  123,456
 */


int main()
{
    int * a[] = {
// 在此处补充你的代码
// 注意，此处不需要对a[]进行初始赋值,而且如果a[0]不为0/null则不会打印结果
        nullptr,
        nullptr,
        new int,
        new int[6]
// 结束
    };

    *a[2] = 123;
    a[3][5] = 456;
    if(! a[0] ) {
        cout << * a[2] << "," << a[3][5];
    }
    return 0;
}