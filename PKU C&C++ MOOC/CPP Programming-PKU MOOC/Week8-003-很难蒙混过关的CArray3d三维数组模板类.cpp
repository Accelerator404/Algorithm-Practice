#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
/**
 * PKU 程序设计与算法慕课（三） 第8周测验(2019夏季)
 * 003:很难蒙混过关的CArray3d三维数组模板类
 *
 * 描述：
 * 实现一个三维数组模版CArray3D，可以用来生成元素为任意类型变量的三维数组，输出指定结果
 *
 * 输入：
 * 无
 *
 * 输出：
 * 等同于样例
 */

template <class T>
class CArray3D
{
// 在此处补充你的代码
public:
    class CArray2D{
    private:
        int row,col;
        int _size;
        T* basePTR;
    public:
        CArray2D(){
            basePTR = new T[1];
        }
        CArray2D(int r,int c){
            row = r;
            col = c;
            _size = r*c;
            basePTR = new T[_size+1];
        }
        // 返回行指针
        T*operator[](int i){
            return basePTR+col*i;
        }
        // memset需要重载强制类型转换
        operator T*(){
            return basePTR;
        }
    };
    CArray2D* layers;
    CArray3D(int d,int r,int c){
        layers = new CArray2D[d];
        for (int i = 0; i < d; ++i) {
            layers[i] = CArray2D(r,c);
        }
    }
    // 返回该层的三维数组切片引用
    CArray2D &operator[](int i){
        return layers[i];
    }
// 结束
};

CArray3D<int> a(3,4,5);
CArray3D<double> b(3,2,2);
void PrintA()
{
    for(int i = 0;i < 3; ++i) {
        cout << "layer " << i << ":" << endl;
        for(int j = 0; j < 4; ++j) {
            for(int k = 0; k < 5; ++k)
                cout << a[i][j][k] << "," ;
            cout << endl;
        }
    }
}
void PrintB()
{
    for(int i = 0;i < 3; ++i) {
        cout << "layer " << i << ":" << endl;
        for(int j = 0; j < 2; ++j) {
            for(int k = 0; k < 2; ++k)
                cout << b[i][j][k] << "," ;
            cout << endl;
        }
    }
}

int main()
{

    int No = 0;
    for( int i = 0; i < 3; ++ i ) {
        a[i];
        for( int j = 0; j < 4; ++j ) {
            a[j][i];
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
            a[j][i][i];
        }
    }
    PrintA();
    memset(a[1],-1 ,20*sizeof(int));
    memset(a[1],-1 ,20*sizeof(int));
    PrintA();
    memset(a[1][1],0 ,5*sizeof(int));
    PrintA();

    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 2; ++j )
            for( int k = 0; k < 2; ++k )
                b[i][j][k] = 10.0/(i+j+k+1);
    PrintB();
    int n = a[0][1][2];
    double f = b[0][1][1];
    cout << "****" << endl;
    cout << n << "," << f << endl;

    return 0;
}