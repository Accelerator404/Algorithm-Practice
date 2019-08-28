#include <iostream>
#include <string>
using namespace std;
/**
 * PKU 程序设计与算法慕课（三） 第7周测验(2019夏季)
 * 003:简单的Filter
 *
 * 描述：
 * 编写Filter模板，使得程序产生指定输出 不得编写 Filter函数
 *
 * 输入：
 * 无
 *
 * 输出：
 * MikeJackLucy
 * 3,4,5,
 */

// 在此处补充你的代码
template<typename T1,typename T2>
T1* Filter(T1* p1,T1* p1Range,T1* a2,bool f(T2 u)){
    int count = 0;
    for (auto i = p1; i < p1Range; ++i) {
        if(f(*i)){
            a2[count] = *i;
            count++;
        }
    }
    return a2 + count;
}
// 结束
bool LargerThan2(int n)
{
    return n > 2;
}
bool LongerThan3(string s)
{
    return s.length() > 3;
}

string as1[5] = {"Tom","Mike","Jack","Ted","Lucy"};
string as2[5];
int  a1[5] = { 1,2,3,4,5};
int a2[5];
int main() {
    string * p = Filter(as1,as1+5,as2,LongerThan3);
    for(int i = 0;i < p - as2; ++i)
        cout << as2[i];
    cout << endl;
    int * p2 = Filter(a1,a1+5,a2,LargerThan2);
    for(int i = 0;i < p2-a2; ++i)
        cout << a2[i] << ",";
    return 0;
}
