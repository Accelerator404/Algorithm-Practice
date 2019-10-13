#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

/**
 *  PKU 程序设计与算法慕课（三） C++面向对象 第二周003
 *  003:超简单的复数类
 *  描述
 *  下面程序的输出是：
 *  3+4i
 *  5+6i
 *  请补足Complex类的成员函数。不能加成员变量。
 *
 *  输入
 *  无
 *
 *  输出
 *  3+4i
 *  5+6i
 */

class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
    Complex(){}
    Complex(char s[]){
        string raw(s);
        int p = raw.find_first_of('+');
        r = stod(raw.substr(0,p));
        i = stod(raw.substr(p+1,raw.length()-(p+1)-1));
    }
// 结束
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}