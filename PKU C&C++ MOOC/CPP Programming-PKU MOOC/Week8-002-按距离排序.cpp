#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
/**
 * PKU 程序设计与算法慕课（三） 第8周测验(2019夏季)
 * 002:按距离排序
 *
 * 描述：
 * 程序填空，输出指定结果
 *
 * 输入：
 * 多组数据，每组一行，是一个整数n和一个字符串s
 *
 * 输出：
 * 定义两个整数的距离为两个整数差的绝对值
 * 定义两个字符串的距离为两个字符串长度差的绝对值
 * 对每组数据：
 * 对数组a按和n的距离从小到大排序后输出。距离相同的，值小的排在前面。
 * 然后对数组b，按照和s的距离从小到大输出。距离相同的，字典序小的排在前面
 */

template <class T1,class T2>
struct Closer {
// 在此处补充你的代码
    T1 destination;
    T2 op;
    // 用于比较距离的标的在结构体模板初始化时确定
    Closer(const T1 & dest_val,const T2 & ops):destination(dest_val),op(ops){}
    bool operator()(const T1 & a,const T1 & b){
        // 当距离较小或值/字典序小时排在前面
        if(op(destination,a) < op(destination,b)
            || (op(destination,a)==op(destination,b)&&a<b))
            return true;
        else
            return false;
    }
// 结束
};

int Distance1(int n1,int n2) {
    return abs(n1-n2);
}
int Distance2(const string & s1, const string & s2)
{
    return abs((int)s1.length()- (int) s2.length());
}
int a[10] = { 0,3,1,4,7,9,20,8,10,15};
string b[6] = {"American","Jack","To","Peking","abcdefghijklmnop","123456789"};
int main()
{
    int n;string s;
    while( cin >> n >> s ) {
        sort(a,a+10,Closer<int ,int (*)(int ,int)> (n,Distance1));
        for(int i = 0;i < 10; ++i)
            cout << a[i] << "," ;
        cout << endl;
        sort(b,b+6,Closer<string,int (*)(const string &,const string &  )> (s,Distance2));
        for(int i = 0;i < 6; ++i)
            cout << b[i] << "," ;
        cout << endl;
    }
    return 0;
}