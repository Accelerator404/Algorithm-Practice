#include <iostream>
using namespace std;
//人民币支付
//从键盘输入一指定金额（以元为单位，如345），然后输出支付该金额的各种面额的人民币数量，
//显示100元，50元，20元，10元，5元，1元各多少张，要求尽量使用大面额的钞票。
//输入;一个小于1000的正整数。
//输出分行，每行显示一个整数，从上到下分别表示100元，50元，20元，10元，5元，1元人民币的张数
int main() {
    int cash,temp;
    int n100 = 0,n50 = 0,n20 = 0,n10 = 0,n5 = 0,n1 = 0;
    cin >> cash;
    temp = cash % 100;
    n100 = (cash - temp) / 100;
    if (temp >= 50){
        n50 =1;
        temp -= 50;
    }
    if (temp >= 40){
        n20 = 2;
        temp -= 2*20;
    }
    else if (temp < 40 && temp >= 30){
        n20 = 1;
        n10 = 1;
        temp -= 30;
    }
    else if (temp < 30 && temp >= 20){
        n20 = 1;
        temp -= 20;
    }
    else if (temp < 20 && temp >= 10){
        n10 = 1;
        temp -= 10;
    }
    if (temp < 10 && temp >= 5){
        n5 = 1;
        temp -= 5;
    }
    if (temp < 5 )
        n1 = temp;
    cout << n100 << '\n' << n50 << '\n' << n20 << '\n' << n10 << '\n' << n5 << '\n' << n1 <<endl;
    return 0;
}
