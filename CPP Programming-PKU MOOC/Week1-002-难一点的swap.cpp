#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/**
 *  PKU 程序设计与算法慕课（三） C++面向对象 第一周002
 *  002:难一点的swap
 *  描述
 *  填空，使得程序输出结果是：
 *  5,3
 *
 *  输入
 *  无。
 *
 *  输出
 *  5,3
 */


void swap(
// 在此处补充你的代码
int * & a,int * & b
// 结束
)
{
    int * tmp = a;
    a = b;
    b = tmp;
}
int main()
{
    int a = 3,b = 5;
    int * pa = & a;
    int * pb = & b;
    swap(pa,pb);
    cout << *pa << "," << * pb;
    return 0;
}