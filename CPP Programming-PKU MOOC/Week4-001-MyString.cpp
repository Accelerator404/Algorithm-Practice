#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/**
 * PKU 程序设计与算法慕课（三） C++面向对象 第四周001
 * 001:MyString
 * 描述
 * 补足MyString类，使程序输出指定结果
 *
 * 输入：
 * 多组数据，每组一行，是两个不带空格的字符串
 *
 * 输出:
 * 对每组数据，先输出一行，打印输入中的第一个字符串三次
 * 然后再输出一行，打印输入中的第二个字符串三次
 */


class MyString {
    char * p;
public:
    MyString(const char * s) {
        if( s) {
            p = new char[strlen(s) + 1];
            strcpy(p,s);
        }
        else
            p = NULL;

    }
    ~MyString() { if(p) delete [] p; }
// 在此处补充你的代码
    MyString(const MyString & src){
        if(src.p){
            p = new char[strlen(src.p) + 1];
            strcpy(p,src.p);
        } else
            p = nullptr;
    }
    MyString & operator=(const MyString & s){
        if(p == s.p)
            return * this;
        delete [] p;
        if(s.p == nullptr)
            return * this;
        p = new char[strlen(s.p) + 1];
        strcpy(p,s.p);
        return * this;
    }
    MyString & operator=(const char* s){
        delete [] p;
        p = new char[strlen(s) + 1];
        strcpy(p,s);
        return * this;
    }
    void Copy(const char* src){
        if(p)
            delete [] p;
        p = new char[strlen(src) + 1];
        strcpy(p,src);
    }
    friend ostream & operator<<(ostream &os,MyString & my){
        os << my.p;
        return os;
    }
// 结束
};
int main()
{
    char w1[200],w2[100];
    while( cin >> w1 >> w2) {
        MyString s1(w1),s2 = s1;
        MyString s3(NULL);
        s3.Copy(w1);
        cout << s1 << "," << s2 << "," << s3 << endl;

        s2 = w2;
        s3 = s2;
        s1 = s3;
        cout << s1 << "," << s2 << "," << s3 << endl;

    }
}