#include <iostream>
using namespace std;
//分数求和
//输入第一行为分数个数n，之后输入n行，每行一个分数
//输出一行、一个分数和（约分后）
//输入的分数均是正数
int main() {
    int n;
    cin >> n;
    int sumnum=1,sumdeno=1;//储存分子与分母的和，为便于启动额外赋予初值1
    for (int i=0;i<n;i++){
        int num;//分子
        char slash;//分号
        int deno;//分母
        cin >> num >> slash >> deno;
        //以下用欧几里得法求每一步分母最大公约数，避免分母溢出
        int a = sumdeno,b = deno,c;
        while (a!= 0) {
            c = a; a = b%a ;b = c;
        }
        int gcd = b;

        deno /= gcd;
        sumdeno /= gcd;
        sumnum =  sumnum * deno + num * sumdeno;//通分后分子求和
        sumdeno = sumdeno * deno * gcd;//分母通分
    }
    sumnum = sumnum - sumdeno;//减去分子初始值1
    //以下欧几里得法求分子分母最大公约数
    int a = sumdeno,b = sumnum,c;
    while (a!= 0) {
        c = a; a = b%a ;b = c;
    }
    int gcd = b;

    sumdeno /= gcd;
    sumnum /= gcd;
    if (sumdeno >1)
        cout << sumnum << '/' << sumdeno << endl;
    else
        cout << sumnum << endl;
    return 0;
}
