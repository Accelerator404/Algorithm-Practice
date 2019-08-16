#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/**
 * PKU 程序设计与算法慕课（三） C++面向对象 第五周002
 * 002:继承自string的MyString
 * 描述
 * 程序填空，输出指定结果
 *
 * 输入：
 * 无
 *
 * 输出:
 * (略)
 */


class MyString:public string
{
// 在此处补充你的代码
public:
    // 用初始化列表调用基类string的构造函数
    MyString():string(){}
    MyString(const char *s):string(s){}
    MyString(const MyString & s):string(s){}
    MyString(const string & s):string(s){}
    MyString operator()(int a,int l){
        // 调用继承的substr函数
        return substr(a,l);
    }
    // 结束
};


int main()
{
    MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
    MyString SArray[4] = {"big","me","about","take"};
    cout << "1. " << s1 << s2 << s3<< s4<< endl;
    s4 = s3;
    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;
    s1 = "ijkl-";
    s1[2] = 'A' ;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    sort(SArray,SArray+4);
    for( int i = 0;i < 4;i ++ )
        cout << SArray[i] << endl;
    //s1的从下标0开始长度为4的子串
    cout << s1(0,4) << endl;
    //s1的从下标5开始长度为10的子串
    cout << s1(5,10) << endl;
    return 0;
}