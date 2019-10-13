#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;

/*
 * PKU 程序设计与算法慕课（三） C++面向对象 期末考试
 * 010:编程填空：回调函数
 *
 * 描述
 * 输入x1 x2 x3 x4 x5 ，输出y = x5^5 + x4^4 + x3^3 + x2^2 + x1^1 + 1的y的值
 *
 * 输入
 * 多组数据。第一行是数据组数 n
 * 每组数据为一行,5个整数，x1 x2 x3 x4 x5。数值不大，不必考虑溢出
 *
 * 输出
 * 对每组数据，输出一个整数y， y = x5^5 + x4^4 + x3^3 + x2^2 + x1^1 + 1
 */

class MyFunc
{
// 在此处补充你的代码
private:
    int power;
public:
    MyFunc(int x){
        power = x;
    }
    int operator()(int m){
        return int(pow(m,power));
    }
// 结束
};
int main()
{
    int n;
    cin >> n;
    while(n--) {
        vector<MyFunc> v;
        for (int i = 0; i < 5; ++i)
            v.push_back(MyFunc(i+1));
        int ans = 1;
        for (int i = 0; i < 5; ++i)
        {
            int m;
            cin >> m;
            ans += v[i](m);
        }
        cout << ans <<endl;
    }
}