#include <iostream>
using namespace std;

//判断闰年
//判断某年是否是闰年。
//输入:输入只有一行，包含一个整数a(0 < a < 3000)
//输出:输出包括一行，如果公元a年是闰年输出Y，否则输出N。

int main() {
    //闰年即要能被4整除，且若能被100整除，还需要能被400整除。
    int a;
    cin >> a;
    cin.get();
    if (a % 4 != 0)
        cout << 'N' << endl;
    else {
        if (a % 100 == 0 && a % 400 != 0)
            cout << 'N' << endl;
        else
            cout << 'Y' << endl;
    }
    return 0;
}
