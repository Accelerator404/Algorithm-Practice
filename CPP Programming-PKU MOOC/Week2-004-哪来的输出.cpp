#include <iostream>
using namespace std;

/**
 *  PKU 程序设计与算法慕课（三） C++面向对象 第二周004
 *  004:哪来的输出
 *  描述
 *  下面程序的输出是：
 *  程序填空，输出指定结果
 *
 *  输入
 *  无
 *
 *  输出
 *  3+4i
 *  2
 *  1
 */

class A {
public:
    int i;
    A(int x) { i = x; }
// 在此处补充你的代码
    ~A(){
        cout << i << endl;
    }
// 结束
};
int main()
{
    A a(1);
    A * pa = new A(2);
    delete pa;
    return 0;
}