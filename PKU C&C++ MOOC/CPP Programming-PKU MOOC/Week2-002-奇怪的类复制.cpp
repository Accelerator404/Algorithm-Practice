#include <iostream>

using namespace std;

/**
 *  PKU 程序设计与算法慕课（三） C++面向对象 第二周002
 *  002:奇怪的类复制
 *  描述
 *  程序填空，使其输出9 22 5
 *
 *  输入
 *  无
 *
 *  输出
 *  9
 *  22
 *  5
 */


class Sample {
public:
    int v;
// 在此处补充你的代码
    Sample(){};
    Sample(int u){
        v = u;
    }
    Sample(const Sample & s){
        v = s.v + 2;
    }
// 结束
};
void PrintAndDouble(Sample o)
{
    cout << o.v;
    cout << endl;
}
int main()
{
    Sample a(5);
    Sample b = a;
    PrintAndDouble(b);
    Sample c = 20;
    PrintAndDouble(c);
    Sample d;
    d = a;
    cout << d.v;
    return 0;
}