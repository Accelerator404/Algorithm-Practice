#include <iostream>
using namespace std;
/**
 * PKU 程序设计与算法慕课（三） 第6周测验(2019夏季)
 * 001:看上去像多态
 *
 * 描述：
 * 程序填空产生输出
 *
 * 输入：
 * 无
 *
 * 输出:
 * D::Fun
 * B::Fun
 * D::Fun
 * nBVal=2
 * nBVal=24
 * nDVal=8
 * B::Fun
 * nBVal=12
 */

class B {
private:
    int nBVal;
public:
    void Print()
    { cout << "nBVal="<< nBVal << endl; }
    void Fun()
    {cout << "B::Fun" << endl; }
    B ( int n ) { nBVal = n;}
};
// 在此处补充你的代码
class D:public B{
private:
    int nDVal;
public:
    D(int i):B(i*3){
        nDVal = i;
    }
    void Fun(){
        cout << "D::Fun" << endl;
    }
    void Print(){
        B::Print();
        cout << "nDVal="<< nDVal << endl;
    }
};
// 结束
int main() {
    B * pb; D * pd;
    D d(4); d.Fun();
    pb = new B(2); pd = new D(8);
    pb -> Fun(); pd->Fun();
    pb->Print (); pd->Print ();
    pb = & d; pb->Fun();
    pb->Print();
    return 0;
}