#include <iostream>
#include <string>
using namespace std;

/*
 * PKU 程序设计与算法慕课（三） C++面向对象 期末考试
 * 001:编程填空：二进制输出
 *
 * 描述
 * 给出一个int表示范围内的正整数x，输出其二进制表示。一共要输出31位，不足处要补0。
 *
 * 输入
 * 第一行是整数n(n<15)，表示有n个正整数要处理
 * 第二行是n个正整数
 *
 * 输出
 * 对每个给出的正整数，输出其二进制表示。不足31位则用0补齐到31位
 */

string dec2bin(int x){
// 在此处补充你的代码
    string result(31,'0');
    for (int i = 0; i < 31; ++i) {
        int param = 1<<(30-i);
        if(param <= x){
            x -= param;
            result[i] = '1';
        }
    }
    return result;
// 结束
}
int main(){
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        cout << dec2bin(x) << endl;
    }
    return 0;
}