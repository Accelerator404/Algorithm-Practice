#include <iostream>
#include <set>

using namespace std;

/*
 * PKU 程序设计与算法慕课（三） C++面向对象 期末考试
 * 015:编程填空：矩形排序
 *
 * 描述
 * 给定一系列边长已知的矩形，输出对矩形进行两种排序的结果。
 * 在第一种排序中，先按矩形的面积从大到小排序；若两个矩形的面积相同，则周长大的排在前。
 * 在第二种排序中，先按矩形的周长从小到大排序；若两个矩形的周长相同，则面积小的排在前。
 *
 * 输入
 * 第一行是一个整数n，表示输入的矩形个数。
 * 接下来n行表示了n个矩形。每行有两个整数a与b，表示该矩形的长与宽。
 *
 * 输出
 * 先用n行输出第一种排序的结果。每行两个整数，依次表示该矩形的面积与周长。
 * 再输出一个空行。
 * 最后用n行输出第二种排序的结果。每行两个整数，依次表示该矩形的面积与周长。
 */

// 在此处补充你的代码
class Rectangle {
private:
    int l, w, size, c;
public:
    Rectangle(int a, int b) {
        l = a;
        w = b;
        size = a * b;
        c = (a + b) * 2;
    }
    friend bool operator < (const Rectangle & a, const Rectangle & b){
        if(a.size > b.size)
            return true;
        else if(a.size == b.size){
            if(a.c > b.c)
                return true;
            else
                return false;
        } else
            return false;
    }
    friend ostream &operator<<(ostream & os,const Rectangle & r){
        os << r.size << ' ' << r.c;
        return os;
    }
    friend class Comp;
};

class Comp{
public:
    bool operator()(const Rectangle & a,const Rectangle & b){
        if(a.c < b.c)
            return true;
        else if(a.c == b.c){
            if(a.size < b.size)
                return true;
            else
                return false;
        } else
            return false;
    }
};

// 结束
int main() {
    multiset<Rectangle> m1;
    multiset<Rectangle, Comp> m2;
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        m1.insert(Rectangle(a, b));
        m2.insert(Rectangle(a, b));
    }
    for (multiset<Rectangle>::iterator it = m1.begin(); it != m1.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
    for (multiset<Rectangle>::iterator it = m2.begin(); it != m2.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}