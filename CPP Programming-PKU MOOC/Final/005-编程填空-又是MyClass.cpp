#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;

/*
 * PKU 程序设计与算法慕课（三） C++面向对象 期末考试
 * 005:编程填空：又是MyClass
 *
 * 描述
 * 补充下列代码，使得程序能够按要求输出
 *
 * 输入
 * 第一行是整数t表示数据组数
 * 每组数据有两行
 * 第一行开头是整数m，然后后面是m个整数(5 < m < 30)
 * 第二行是一个没有空格的字符串，长度不超过50
 *
 * 输出
 * 对每组数据 先输出m个整数中的第5个，然后输出字符串中的第7个字符。
 * "第i个"中的 i 是从0开始算的。
 */

// 在此处补充你的代码
template <typename T>
class CMyClass{
private:
T* arrayPtr;
int arraySize;
public:
    CMyClass(T* array,int size){
        arrayPtr = new T[size];
        arraySize = size;
        memcpy(arrayPtr,array,size*sizeof(T));
    }
    T operator[](unsigned i){
        return arrayPtr[i];
    }
};
int  a[40];
int main(int argc, char** argv) {
    int t;
    scanf("%d",&t);
    while ( t -- ) {
        int m;
        scanf("%d",&m);
        for (int i = 0;i < m; ++i)
            scanf("%d",a+i);
        char s[100];
        scanf("%s",s);
        CMyClass<int> b(a, m);
        CMyClass<char> c(s, strlen(s));
        printf("%d %c\n", b[5], c[7]);
    }
    return 0;
}