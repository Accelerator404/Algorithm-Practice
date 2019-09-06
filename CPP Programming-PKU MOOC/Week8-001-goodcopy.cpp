#include <iostream>
using namespace std;
/**
 * PKU 程序设计与算法慕课（三） 第8周测验(2019夏季)
 * 001:goodcopy
 *
 * 描述：
 * 编写GoodCopy类模板，使得程序按指定方式输出
 *
 * 输入：
 * 第一行是整数 t,表示数据组数
 * 每组数据：
 * 第一行是整数 n , n < 50
 * 第二行是 n 个整数
 * 第三行是 n 个字符串
 *
 * 输出：
 * 将输入的整数原序输出两次，用","分隔
 * 然后将输入的字符串原序输出两次，也用 ","分隔
 */

template <class T>
struct GoodCopy {
// 在此处补充你的代码
    void copydata(T* begin,T* end,T* p){
        for (T* i = end - 1; i >= begin; --i) {
            *(p + (i - begin)) = *i;
        }
    }
    void operator()(T* b,T* e,T* p){
        copydata(b,e,p);
    }
// 结束
};

int a[200];
int b[200];
string c[200];
string d[200];

template <class T>
void Print(T s,T e) {
    for(; s != e; ++s)
        cout << * s << ",";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while( t -- ) {
        int m ;
        cin >> m;
        for(int i = 0;i < m; ++i)
            cin >> a[i];
        GoodCopy<int>()(a,a+m,b);
        Print(b,b+m);
        GoodCopy<int>()(a,a+m,a+m/2);
        Print(a+m/2,a+m/2 + m);

        for(int i = 0;i < m; ++i)
            cin >> c[i];
        GoodCopy<string>()(c,c+m,d);
        Print(c,c+m);
        GoodCopy<string>()(c,c+m,c+m/2);
        Print(c+m/2,c+m/2 + m);
    }
    return 0;
}