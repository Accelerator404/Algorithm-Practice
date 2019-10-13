#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/**
 *  PKU 程序设计与算法慕课（一） C++面向对象 第一周002
 *  002:字符菱形
 *  描述
 *  给定一个字符，用它构造一个对角线长5个字符，倾斜放置的菱形。
 *
 *  输入
 *  输入只有一行， 包含一个字符。
 *
 *  输出
 *  该字符构成的菱形。
 */

int main(){
    char c;
    cin >> c;
    for(int i = 1;i <= 25;i++){
        if(i==3 || i==23 || (i>=7&&i<=19&&i!=10&&i!=16))
            printf("%c",c);
        else
            printf(" ");
        if(i%5==0)
            printf("\n");
    }
    return 0;
}
