#include <iostream>
#include <iomanip>
using namespace std;

//简单计算器
//一个最简单的计算器，支持+, -, *, / 四种运算。仅需考虑输入输出为整数的情况，数据和运算结果不会超过int表示的范围。
//输入:输入只有一行，共有三个参数，其中第1、2个参数为整数，第3个参数为操作符（+,-,*,/）。
//输出:输出只有一行，一个整数，为运算结果。然而：
// 1. 如果出现除数为0的情况，则输出：Divided by zero!
// 2. 如果出现无效的操作符(即不为 +, -, *, / 之一），则输出：Invalid operator!



int main() {
    int x,y;
    char symbol;
    cin >> x >> y >> symbol;
    cin.get();
    switch(symbol){
        case '+' : cout << x + y << endl;break;
        case '-' : cout << x - y << endl;break;
        case '*' : cout << x * y << endl;break;
        case '/' :
            if(y != 0)
                cout << x / y << endl;
            else
                cout << "Divided by zero!" << endl;
            break;
        default: cout << "Invalid operator!" <<endl;
    }
    return 0;
}
