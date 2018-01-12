#include <iostream>
using namespace std;

/**
 *  含k个3的数
 *
 *  描述
 *  输入二个正整数m 和 k，其中1 < m < 100000，1 < k <5 ，判断m 能否被19整除，且恰好含有k个3，
 *  如果满足条件，则输出YES，否则，输出NO。
 *  例如，输入：
 *  43833 3
 *  满足条件，输出YES
 *  如果输入：
 *  39331 3
 *  尽管有3个3，但不能被19整除，也不满足条件，应输出NO
 *
 *  输入
 *  m 和 k 的值，空格间隔
 *
 *  输出
 *  满足条件时输出 YES，不满足时输出 NO
 *
*/
bool count3(int m,int k){
    int count = 0,temp = m,level = 10000;
    //从5位开始统计数字3个数
    while(true){
        if(level == 0)
            break;
        if(temp / level == 3)
            count++;
        temp = temp % level;
        level /= 10;
    }
    if(count == k)
        return true;
    else
        return false;
}

int main() {
    int m,k;
    cin >> m >> k;;
    bool p1 = m % 19 == 0;
    bool judge = count3(m,k);
    if(p1 && judge)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
