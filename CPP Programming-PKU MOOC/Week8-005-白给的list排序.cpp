#include <cstdio>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
/**
 * PKU 程序设计与算法慕课（三） 第8周测验(2019夏季)
 * 005:白给的list排序
 *
 * 描述：
 * 程序填空，产生指定输出
 *
 * 输入：
 * 无
 *
 * 输出：
 * 9.8,7.3,3.4,2.6,1.2,
 */
int main()
{
    double a[] = {1.2,3.4,9.8,7.3,2.6};
    list<double> lst(a,a+5);
    lst.sort(
// 在此处补充你的代码
// 通过前面几道模板类的题目，可以看出该类型的原理了
greater<double>()
// 结束
);

    for(list<double>::iterator i  = lst.begin(); i != lst.end(); ++i)
        cout << * i << "," ;
    return 0;
}