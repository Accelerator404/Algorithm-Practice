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
 * 006:编程填空：去除重复元素排序
 *
 * 描述
 * 程序填空，使其按要求输出
 *
 * 输入
 * 第一行是个整数，表示输入数据组数
 * 每组数据一行,有12个整数
 *
 * 输出
 * 对每组数据, 将12个整数从小到大排序并去除重复元素后输出
 */

int main() {
    int t;
    int  a[100];
    cin >> t;
    while(t--) {
        for(int i = 0;i < 12; ++i)
            cin >> a[i];
// 在此处补充你的代码
        set<int> s;
        for (int i = 0;i < 12;i++) {
            s.insert(a[i]);
        }
        vector<int> b,u;
        auto c = u.begin();
        for (set<int>::iterator iter = s.begin();iter != s.end();iter++) {
            cout << *iter << ' ';
        }
// 结束
        std::copy(b.begin(), b.end(), c);
        cout << endl;

    }
    return 0;
}