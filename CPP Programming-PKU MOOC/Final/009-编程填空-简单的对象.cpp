#include <iostream>
using namespace std;

/*
 * PKU 程序设计与算法慕课（三） C++面向对象 期末考试
 * 009:编程填空：简单的对象
 *
 * 描述
 * 程序填空，使得程序输出:
 * 2
 * 1
 * 1
 * 0
 *
 * 输入
 * 无
 *
 * 输出
 * (略)
 */

class A
{
    static int num;
public:
    A(){num+=1;}
    void func()
    {
        cout<< num <<endl;
    }
// 在此处补充你的代码
    void func() const{
        num -=1;
        cout << num << endl;
    }
// 结束
};

int A::num=1;

int main()
{
    A a1;
    const A a2 = a1;
    A & a3 = a1;
    const A & a4 = a1;

    a1.func();
    a2.func();
    a3.func();
    a4.func();

    return 0;
}