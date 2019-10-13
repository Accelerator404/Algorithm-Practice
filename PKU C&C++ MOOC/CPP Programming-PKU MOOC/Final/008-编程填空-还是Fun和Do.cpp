#include <iostream>
using namespace std;

/*
 * PKU 程序设计与算法慕课（三） C++面向对象 期末考试
 * 008:编程填空：还是Fun和Do
 *
 * 描述
 * 填写代码，使输出结果为
 * A::Fun
 * B::Do
 * C::Fun
 * C::Do
 * A::Fun
 * B::Do
 *
 * 输入
 * 无
 *
 * 输出
 * (略)
 */

class A {
public:
    virtual void Fun() {
        cout << "A::Fun" << endl;
    };
    virtual void Do() {
        cout << "A::Do" << endl;
    }
};
// 在此处补充你的代码
class B:public A{
public:
    virtual void Do(){
        cout << "B::Do" << endl;
    }
};
class C:public B{
public:
    void Fun() {
        cout << "C::Fun" << endl;
    };
    void Do(){
        cout << "C::Do" << endl;
    }
};
void Call1(A &p)    // 这里如果不使用引用，会拷贝一个A类型的，不包含任何B、C派生类信息的副本
// 结束
{
    p.Fun();
    p.Do();
}

void Call2(B p) {
    p.Fun();
    p.Do();
}



int main() {
    C c;
    B b;
    Call1(b);
    Call1(c);
    Call2(c);
    return 0;
}