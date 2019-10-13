#include <iostream>
using namespace std;

//进制转换
//递归的应用

void dec2bin(int n) {
    int temp;
    temp = n / 2;
    if (temp != 0)
        dec2bin(temp);
    cout << n % 2;
}

int main() {
    int n;
    cin >> n;
    dec2bin(n);
    cout << endl;
    return 0;
}
