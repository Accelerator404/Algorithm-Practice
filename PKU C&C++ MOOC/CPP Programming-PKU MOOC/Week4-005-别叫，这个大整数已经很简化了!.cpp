#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

/**
 * PKU 程序设计与算法慕课（三） C++面向对象 第四周005
 * 005:别叫，这个大整数已经很简化了!
 * 描述
 * 程序填空，输出指定结果
 *
 * 输入：
 * 多组数据，每组数据是两个非负整数s和 n。s最多可能200位， n用int能表示
 *
 * 输出:
 * 对每组数据，输出6行，内容分别是：(略)
 */

/**
 * 笔记
 * 大整数类已经写过很多次了，在这里要注意的是：
 * 1.友元函数，相当于可以访问private参数的普通函数，所以通过友元函数就可以在类内部实现两参数的加号超载；
 * 2.涉及赋值符号=的超载，比如+=，声明类型带引用，返回*this；
 * 3.流运算符<<,>>的超载函数的类型是i/ostream&，是参数包含i/ostream引用的友元函数；
 * 4.自增符号分前后置两类，后置时多一个占位参量，且【由于要返回自增前的数值，函数声明不带引用】
 */

const int MAX = 110;
class CHugeInt {
// 在此处补充你的代码
private:
    string raw;
public:
    CHugeInt(){}
    CHugeInt(int n){
        raw = to_string(n);
    }
    CHugeInt(char* s){
        string tmp(s);
        raw = tmp;
    }
    CHugeInt(const CHugeInt & B){
        string tmp(B.raw);
        raw = tmp;
    }
    // 判断两个非负整数的大小
    inline static int compare(const CHugeInt & a,const CHugeInt & b){
        if(a.raw.length() < b.raw.length())
            return -1;
        else if(a.raw.length() > b.raw.length())
            return 1;
        for (int i = 0; i < a.raw.length(); ++i) {
            if(a.raw[i] > b.raw[i])
                return 1;
            else if(a.raw[i] < b.raw[i])
                return -1;
        }
        return 0;
    }
    // 将以实现n+a为目的的超载函数声明为友元函数
    friend CHugeInt operator+(const CHugeInt & A,const CHugeInt & B){
        CHugeInt result;
        string leftNum = A.raw;
        string rightNum = B.raw;
        if(compare(A,B) < 0){
            leftNum = B.raw;
            rightNum = A.raw;
        }
        //在不能使用reverse函数的时候采用标准的从低位到高位相加
        int pivot_left = leftNum.length() - 1;
        int pivot_right = rightNum.length() - 1;
        bool carry = false;
        result.raw.assign(leftNum.length()+1,'0');
        int pivot_result = result.raw.length() - 1;
        while (pivot_result >= 0){
            if(pivot_left >= 0){
                result.raw[pivot_result] += leftNum[pivot_left] - '0';
                pivot_left--;
            }
            if(pivot_right >= 0){
                result.raw[pivot_result] += rightNum[pivot_right] - '0';
                pivot_right--;
            }
            if(carry){
                result.raw[pivot_result]++;
                carry = false;
            }
            if(result.raw[pivot_result] > '9'){
                carry = true;
                result.raw[pivot_result] = (result.raw[pivot_result] - '0')%10 + '0';
            }
            pivot_result--;
        }
        while(result.raw[0] == '0' && result.raw.length() > 1){
            result.raw = result.raw.substr(1,string::npos);
        }
        return result;
    }
    CHugeInt &operator+=(const CHugeInt & B){
        CHugeInt tmpResult = *this + B;
        raw = tmpResult.raw;
        return *this;
    }
    friend ostream & operator<<(ostream & os, const CHugeInt & A){
        os << A.raw;
        return os;
    }
    CHugeInt &operator++(){
        *this += 1;
        return *this;
    }
    CHugeInt operator++(int u){
        CHugeInt previous(*this);
        *this += 1;
        return previous;
    }
// 结束
};
int  main()
{
    char s[210];
    int n;

    while (cin >> s >> n) {
        CHugeInt a(s);
        CHugeInt b(n);

        cout << a + b << endl;
        cout << n + a << endl;
        cout << a + n << endl;
        b += n;
        cout  << ++ b << endl;
        cout << b++ << endl;
        cout << b << endl;
    }
    return 0;
}