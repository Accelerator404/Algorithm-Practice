#include <iostream>
using namespace std;

/*
 * PKU 程序设计与算法慕课（三） C++面向对象 期末考试
 * 003:编程填空：简单的计算
 *
 * 描述
 * 补充代码，使程序按要求输出
 *
 * 输入
 * 有若干组数据
 * 每组数据三行
 * 第一行是一个浮点数f和一个整数 n
 * 第二行是两个浮点数 x 和 y
 * 第三行是两个整数 p 和q
 *
 * 输出
 * 对每组数据
 * 先输出 x + y - f
 * 再输出 p + q - n
 */
template <class T>
class Add{
public:
// 在此处补充你的代码
    T minus;
    Add(T token){
        minus = token;
    }
    T operator()(T x,T y){
        return x+y-minus;
    }
// 结束
};

int main(){
    double f;
    int n;
    while( cin >> f >> n) {

        Add<double> a1(f);
        Add<int> a2(n);
        double x,y;
        int p,q;
        cin >> x >> y >> p >> q;
        cout << a1(x, y) << endl;
        cout << a2(p, q) << endl;
    }
    return 0;
}