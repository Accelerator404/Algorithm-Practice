#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 蓝桥杯练习 BASIC-19 完美的代价

// 循环宏
#define _for(i, a, b) for(int i = (a); i < b;i++)

// 整数读取
long long int readint() {
    long long int tmp;
    scanf("%lld", &tmp);
    return tmp;
}


int main() {
    int N = readint();
    string s;
    cin >> s;
    // 以下一边扫描配对字符，一边进行移动
    // 设指针i=0,j=N-1，每次循环到最后均会确保s[i]==s[j]，否则s[i]无法配对（s内有奇数个该字符）
    // 再判断s是否无法形成回文串。
    int j = N - 1;
    int count = 0;
    bool flag = false;
    // 注意以下循环中，上界j会不断减小
    _for(i, 0, j) {
        // 倒序寻找与s[i]匹配的字符
        for (int k = j; k >= i; --k) {
            if (k == i) {
                // 如果存在某种字符有奇数个，且字符串长度为偶数；
                // 或者字符串长度为奇数，但已经存在一个个数为奇数的字符了
                // 则该串无法构成回文串
                if (N % 2 == 0 || flag) {
                    cout << "Impossible" << endl;
                    return 0;
                }
                flag = true;
                // 字符s[i]到中点的距离，即最后将其移到中间需要的步数
                count += N / 2 - i;
            }
                // 找到匹配的字符
            else if (s[k] == s[i]) {
                // s[k] ----> s[j]
                for (int l = k; l < j; ++l) {
                    swap(s[l], s[l + 1]);
                    count++;
                }
                // 对称字符完成，右侧位置左移1个字符，继续判断s[i+1]的位置
                j--;
                break;
            }
        }
    }
    cout << count << endl;
    return 0;
}
