#include <iostream>
using namespace std;
/**
 * PKU 程序设计与算法慕课（三） 第6周测验(2019夏季)
 * 004:怎么又是Fun和Do
 *
 * 描述：
 * 程序填空产生输出
 *
 * 输入：
 * 无
 *
 * 输出:
 * A::Fun
 * A::Do
 * A::Fun
 * C::Do
 */
class A {
private:
    int nVal;
public:
    void Fun()
    { cout << "A::Fun" << endl; };
    virtual void Do()
    { cout << "A::Do" << endl; }
};
class B:public A {
public:
    virtual void Do()
    { cout << "B::Do" << endl;}
};
class C:public B {
public:
    void Do( )
    { cout <<"C::Do"<<endl; }
    void Fun()
    { cout << "C::Fun" << endl; }
};
void Call(
// 在此处补充你的代码
    A * p
// 结束
) {
    p->Fun(); p->Do();
}
int main() {
    Call( new A());
    Call( new C());
    return 0;
}