#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/**
 *  PKU 程序设计与算法慕课（三） C++面向对象 第一周003
 *  003:好怪异的返回值
 *  描述
 *  填空，使得程序输出指定结果
 *
 *  输入
 *  无。
 *
 *  输出
 *  10
 */


// 在此处补充你的代码
int &
// 结束
getElement(int * a, int i)
{
    return a[i];
}
int main()
{
    int a[] = {1,2,3};
    getElement(a,1) = 10;
    cout << a[1] ;
    return 0;
}