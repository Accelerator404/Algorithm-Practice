#include <iostream>
using namespace std;

/**
 * PKU 程序设计与算法慕课（三） C++面向对象 第四周003
 * 003:惊呆！Point竟然能这样输入输出
 * 描述
 * 程序填空
 *
 * 输入：
 * 多组数据，每组两个整数
 *
 * 输出:
 * 对每组数据，输出一行，就是输入的两个整数
 */

class Point {
private:
    int x;
    int y;
public:
    Point() { };
// 在此处补充你的代码
    friend istream & operator>>(istream & is,Point & u){
        is >> u.x >> u.y ;
        return is;
    }
    friend ostream & operator<<(ostream & os,Point & u){
        os << u.x << ',' << u.y;
        return os;
    }
// 结束
};
int main()
{
    Point p;
    while(cin >> p) {
        cout << p << endl;
    }
    return 0;
}