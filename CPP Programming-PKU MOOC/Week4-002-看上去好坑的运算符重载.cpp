#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/**
 * PKU 程序设计与算法慕课（三） C++面向对象 第四周002
 * 002:看上去好坑的运算符重载
 * 描述
 * 程序填空
 *
 * 输入：
 * 多组数据，每组一行，整数n
 *
 * 输出:
 * 对每组数据，输出一行，包括两个整数， n-5和n - 8
 */


class MyInt
{
    int nVal;
public:
    MyInt( int n) { nVal = n ;}
// 在此处补充你的代码
    MyInt& operator-(int n){
        nVal-= n;
        return *this;   //注意这里连续减法的形式，需要传回引用实现
    }
    operator int(){
        return nVal;
    }
// 结束
};
int Inc(int n) {
    return n + 1;
}
int main () {
    int n;
    while(cin >>n) {
        MyInt objInt(n);
        objInt-2-1-3;
        cout << Inc(objInt);
        cout <<",";
        objInt-2-1;
        cout << Inc(objInt) << endl;
    }
    return 0;
}