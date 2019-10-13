#include <iostream>
#include <cstring>
using namespace std;

/**
 * PKU 程序设计与算法慕课（三） C++面向对象 第四周004
 * 004:第四周程序填空题3
 * 描述
 * 写一个二维数组类 Array2,使得下面程序的输出结果是：
 * 0,1,2,3,
 * 4,5,6,7,
 * 8,9,10,11,
 * next
 * 0,1,2,3,
 * 4,5,6,7,
 * 8,9,10,11,
 *
 * 输入：
 * 无
 *
 * 输出:
 * 0,1,2,3,
 * 4,5,6,7,
 * 8,9,10,11,
 * next
 * 0,1,2,3,
 * 4,5,6,7,
 * 8,9,10,11,
 */

class Array2 {
// 在此处补充你的代码
private:
    int size;   // 用一维数组按行存储矩阵，不考虑可变
    int col;
    int row;
    int* p;
    int m2vec(int r,int c){
        int pos = r * col + c;
        return pos;
    }
public:
    // 实现构造函数与复制函数
    Array2(int r,int c){
        row = r;
        col = c;
        size = r * c;
        p = new int[size];
    }
    Array2(){
        size = row = col = 0;
        p = nullptr;
    }
    Array2(const Array2 & m){
        size = m.size;
        col = m.col;
        row = m.row;
        p = new int[size];
        memcpy(p,m.p,sizeof(int) * size);
    }
    // 超载赋值符
    Array2 & operator= (const Array2 & a){
        if(p) delete [] p;
        size = a.size;
        col = a.col;
        row = a.row;
        p = new int[size];
        memcpy(p,a.p,sizeof(int) * size);
        return *this;
    }
    ~Array2(){
        if(p) delete[] p;
    }
    int & operator() (int i,int j){
        return p[m2vec(i,j)];
    }
    // 为了实现二维数组的直接访问，将其分解为两步：获得该行地址、在该行内获得目标[行][列]元素的引用。
    // 只要重载Matrix[]，返回一个int*形式的i行首地址，
    // 接下来通过int*[]即可以默认一维数组内寻址的方式返回目标元素的引用
    int * operator[](int i){
        return p + i * col;
    }
// 结束
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}