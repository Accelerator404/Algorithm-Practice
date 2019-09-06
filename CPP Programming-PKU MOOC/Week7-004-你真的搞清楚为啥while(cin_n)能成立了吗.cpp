#include <iostream>
using namespace std;
/**
 * PKU 程序设计与算法慕课（三） 第7周测验(2019夏季)
 * 004:你真的搞清楚为啥 while(cin >> n) 能成立了吗？
 *
 * 描述：
 * 读入两个整数，输出两个整数 ，直到碰到-1
 *
 * 输入：
 * 多组数据，每组一行，是两个整数
 *
 * 输出：
 * 对每组数据，原样输出
 * 当碰到输入中出现-1 时，程序结束
 * 输入中保证会有 -1
 */
class MyCin
{
// 在此处补充你的代码
private:
    bool status = true;
public:
    MyCin & operator >>(int & n)
    {
        int x;
        cin >> x;
        n = x;
        if (n == -1)
            status = false;
        return *this;
    }
    // 强制类型转换
    operator bool()
    {
        return status;
    }
// 结束
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2)
        cout  << n1 << " " << n2 << endl;
    return 0;
}
