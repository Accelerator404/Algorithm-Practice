#include <iostream>
using namespace std;

/**
 *  PKU 程序设计与算法慕课（三） C++面向对象 第三周001
 *  001:返回什么才好呢
 *  描述
 *  程序填空，使其按要求输出
 *
 *  输入
 *  多组数据，每组一行，是整数 m 和 n
 *
 *  输出
 *  先输出一行：
 *  123
 *  然后，对每组数据，输出两行，第一行是m,第二行是n
 */

class A {
public:
    int val;

    A(int
// 在此处补充你的代码
    n){val = n;}
    // 默认初始值为123
    A(){val = 123;}
    A & GetObj(){
        // 返回一个该对象的引用
        return *this;
    }
// 结束
};
int main()
{
    int m,n;
    A a;
    cout << a.val << endl;
    while(cin >> m >> n) {
        a.GetObj() = m;
        cout << a.val << endl;
        a.GetObj() = A(n);
        cout << a.val<< endl;
    }
    return 0;
}