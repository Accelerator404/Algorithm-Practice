#include <iostream>
#include <iomanip>
using namespace std;

/**
 * 实数的输出格式
 *
 * 描述
 * 利用流操纵算子实现： 输入一个实数，先以非科学计数法输出，小数点后面保留5位有效数字；再以科学计数法输出，小数点后面保留7位有效数字。
 * 注意：在不同系统、编译器上的输出格式略有不同，但保证在程序中采用默认格式设置一定能在OJ平台上得到正确结果。
 *
 * 输入
 * 以非科学计数法表示的一个正实数，保证可以用double类型存储。
 *
 * 输出
 * 第一行：以非科学计数法输出该实数，小数点后面保留5位有效数字；
 * 第二行：以科学计数法输出该实数，小数点后面保留7位有效数字。
 *
 */

int main()
{
    double a;
    cin >> a;
    cout << setiosflags(ios::fixed) << setprecision(5) << a << endl;
    //接下来需要移除固定精度flag，使用cout.unsetf子函数
    cout.unsetf(ios::fixed);
    cout << setiosflags(ios::scientific) << setprecision(7) << a << endl;
    return 0;
}
