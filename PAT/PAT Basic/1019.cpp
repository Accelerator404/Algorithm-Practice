#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

#define _for(i, a, b) for(int i = (a); i < b;i++)

// PAT Basic 1019. 数字黑洞

int recur(int N) {
    string num = std::to_string(N);
    while (num.length() < 4)
        num = "0" + num;
    sort(num.begin(), num.end(), [](char a, char b) -> bool { return a >= b; });
    string num2(num);
    reverse(num2.begin(), num2.end());
    int result = stoi(num, nullptr, 10) - stoi(num2, nullptr, 10);
    printf("%s - %s = %04d\n", num.c_str(), num2.c_str(), result);
    return result;
}

int main() {
    int N;
    cin >> N;
    while (true) {
        N = recur(N);
        if (N == 0 || N == 6174)
            break;
    }
    return 0;
}
