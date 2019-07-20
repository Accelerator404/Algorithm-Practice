#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/**
 *  PKU 程序设计与算法慕课（三） C++面向对象 第一周001
 *  001:简单的swap
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

class A{
    public:
        int x;
        int getX() { return x; }
};
void swap(
// 在此处补充你的代码
A & a,A & b
// 结束
)
{
    int  tmp = a.x;
    a.x = b.x;
    b.x = tmp;
}
int main(){
    A a,b;
    a.x = 3;
    b.x = 5;
    swap(a,b);
    cout << a.getX() << "," << b.getX();
    return 0;
}