#include <iostream>
#include <string>
using namespace std;

/**
 *  PKU 程序设计与算法慕课（三） C++面向对象 第三周002
 *  002:Big & Base 封闭类问题
 *  描述
 *  程序填空，输出指定结果
 *
 *  输入
 *  多组数据，每组一行，是一个整数
 *
 *  输出
 *  对每组数据，输出两行，每行把输入的整数打印两遍
 */

class Base {
public:
    int k;
    Base(int n):k(n) { }
};
class Big
{
public:
    int v;
    Base b;
// 在此处补充你的代码
    Big(int n):v(n),b(n){};
    Big(Big & t):v(t.v),b(t.b){};
// 结束
};
int main()
{
    int n;
    while(cin >>n) {
        Big a1(n);
        Big a2 = a1;
        cout << a1.v << "," << a1.b.k << endl;
        cout << a2.v << "," << a2.b.k << endl;
    }
}