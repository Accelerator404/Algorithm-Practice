#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
using namespace std;

/*
 * PKU 程序设计与算法慕课（三） C++面向对象 期末考试
 * 011:编程填空：前K大的偶数
 *
 * 描述
 * 输入n个整数，输出整数数列中大小排名前k的偶数
 *
 * 输入
 * 有多组数据
 * 第一行是数据组数 t
 * 对每组数据：
 * 第一行为整数n (n>=3)和k
 * 接下来的一行为n个整数，保证这些整数中至少有k个偶数。
 *
 * 输出
 * 对每组数据，输出k个整数，降序排列，表示选出来的大小排名前k的偶数
 */
class MyQueue
{
// 在此处补充你的代码
private:
    int k;
    vector<int> data;
public:
    MyQueue(int val){
        k = val;
    }
    friend istream & operator>>(istream & is,MyQueue & Q){
        int tmp;
        is >> tmp;
        if(tmp%2 == 0)
            Q.data.push_back(tmp);
        return is;
    }
    // 注意超载流插入和流提取运算符时，1.友元，2.引用
    friend ostream & operator<<(ostream & os,MyQueue & Q){
        sort(Q.data.begin(),Q.data.end(),greater<int>());
        int i = 0;
        for (auto iter = Q.data.begin(); iter != Q.data.end() && i < Q.k; ++iter,++i) {
            os << *iter << ' ';
        }
        return os;
    }
// 结束
};
int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        MyQueue q(k);
        for (int i = 0; i < n; ++i)
            cin >> q;
        cout<<q;
        cout << endl;
    }
    return 0;
}