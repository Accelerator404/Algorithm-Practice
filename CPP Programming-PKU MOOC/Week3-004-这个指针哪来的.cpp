#include <iostream>
using namespace std;

/**
 *  PKU 程序设计与算法慕课（三） C++面向对象 第三周004
 *  004:这个指针哪来的
 *  描述
 *  填空，按要求输出
 *
 *  输入
 *  无
 *
 *  输出
 *  10
 */

struct A
{
    int v;
    A(int vv):v(vv) { }
// 在此处补充你的代码
    // 一个返回const A*指针的常量成员函数，而const对象也只能调用const成员函数
    const A * getPointer() const{
        return this;
    }
// 结束
};

int main()
{
    const A a(10);
    const A * p = a.getPointer();
    cout << p->v << endl;
    return 0;
}