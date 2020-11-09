#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 蓝桥杯练习 ADV-9

// 循环宏
#define _for(i, a, b) for(int i = (a); i < b;i++)

// 整数读取
long long int readint() {
    long long int tmp;
    scanf("%lld", &tmp);
    return tmp;
}

void reverse(string & s,int head,int tail){
    if (tail-head <= 0)
        return;
    swap(s[head],s[tail]);
    cout << s << endl;
    reverse(s,head+1,tail-1);
}

int main() {
    int N = readint();
    string s;
    cin >> s;
    reverse(s,0,N-1);
    cout << endl;
    cout << s << endl;
    return 0;
}
