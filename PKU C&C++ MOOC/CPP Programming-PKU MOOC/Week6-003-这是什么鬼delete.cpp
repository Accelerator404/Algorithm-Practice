#include <iostream>
using namespace std;
/**
 * PKU 程序设计与算法慕课（三） 第6周测验(2019夏季)
 * 003:这是什么鬼delete
 *
 * 描述：
 * 程序填空产生输出
 *
 * 输入：
 * 无
 *
 * 输出:
 * destructor B
 * destructor A
 */
class A
{
public:
    A() { }
// 在此处补充你的代码
    virtual ~A(){  cout << "destructor A" << endl; }
// 结束
};
class B:public A {
public:
    ~B() { cout << "destructor B" << endl; }
};
int main()
{
    A * pa;
    pa = new B;
    delete pa;
    return 0;
}