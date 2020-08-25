#include <iostream>
#include <string>

using namespace std;

/*
 * PAT Advanced: 1060. Are They Equal
 */

string BigFloatChopping(string f, unsigned long n) {
    // 判断0。此处既要考虑00.00也要考虑00这样的特例，并直接按位补0返回0.00*10^0这样的形式
    int i = f.find('.');
    string u = f;
    if (i != string::npos) {
        u.erase(i, 1);
    }
    int e = u.find_first_not_of('0');
    if (e < 0) {
        return "0." + string(n, '0') + "*10^0";
    }
    // 头部去0,如果是小于1的纯小数，则此时串头部是小数点
    int z = f.find_first_not_of('0');
    if (z > 0) {
        f = f.substr(z);
    }
    // 获取位数
    int k;
    i = f.find('.');
    if (i == string::npos)
        // 整数
        k = f.size();
    else if (i == 0) {
        f.erase(0, 1);
        k = -f.find_first_not_of('0');
        if (k < 0)
            f.erase(0, -k);
    } else {
        k = i;
        // 去除小数点
        f.erase(i, 1);
    }
    string x = f.substr(0, min(f.length(), n));
    x += string(n - x.length(), '0');
    return "0." + x + "*10^" + to_string(k);
}


int main() {
    int N;
    string A, B;
    cin >> N >> A >> B;
    string res_A = BigFloatChopping(A, N);
    string res_B = BigFloatChopping(B, N);
    cout << ((res_A == res_B) ? ("YES " + res_A) : ("NO " + res_A + ' ' + res_B));

    return 0;
}