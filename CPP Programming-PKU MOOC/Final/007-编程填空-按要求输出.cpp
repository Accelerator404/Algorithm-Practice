#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <iostream>
#include <set>
using namespace std;

/*
 * PKU 程序设计与算法慕课（三） C++面向对象 期末考试
 * 007:编程填空：按要求输出
 *
 * 描述
 * 下列程序的输出为"10 13 18 15 17 12 16 19",  请补充代码
 *
 * 输入
 * 无
 *
 * 输出
 * 10 13 18 15 17 12 16 19
 */

int  a[10] = {0, 6, 7, 3, 9, 5, 8, 6, 4, 9};
int  b[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int main(int argc, char** argv) {
// 在此处补充你的代码
    map<int,int> c;
    auto it = c.begin();
// 结束
    for(int i=0; i<10; i++)
        c[a[i]] = b[i];
    for(it=c.begin(); it!=c.end(); it++)
        cout<<it->second<<" ";
    return 0;
}