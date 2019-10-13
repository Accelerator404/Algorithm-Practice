#include <iostream>
#include <list>
#include <string>
using namespace std;
/**
 * PKU 程序设计与算法慕课（三） 第8周测验(2019夏季)
 * 006:我自己的 ostream_iterator
 *
 * 描述：
 * 程序填空输出指定结果
 *
 * 输入：
 * 无
 *
 * 输出：
 * 5,21,14,2,3,
 * 1.4--5.56--3.2--98.3--3.3--
 */
template <class T1,class T2>
void Copy(T1 s,T1 e, T2 x)
{
    for(; s != e; ++s,++x)
        *x = *s;
}


template<class T>
class myostream_iteraotr
{
// 在此处补充你的代码
public:
    string append;
    ostream&os;
    myostream_iteraotr(ostream& out,string app):os(out),append(app){}
    // 迭代器自增，实际上仅仅返回当前迭代器的值
    myostream_iteraotr& operator++(){
        return *this;
    }
    // 返回迭代器值
    myostream_iteraotr&operator*(){
        return *this;
    }
    myostream_iteraotr&operator=(T & stream){
        os << stream << append;
        return *this;
    }
// 结束
};


int main()
{	const int SIZE = 5;
    int a[SIZE] = {5,21,14,2,3};
    double b[SIZE] = { 1.4, 5.56,3.2,98.3,3.3};
    list<int> lst(a,a+SIZE);
    myostream_iteraotr<int> output(cout,",");
    Copy( lst.begin(),lst.end(),output);
    cout << endl;
    myostream_iteraotr<double> output2(cout,"--");
    Copy(b,b+SIZE,output2);
    return 0;
}