#include <iostream>
#include <vector>
#include <string>
using namespace std;

//PAT Advanced 1065 A+B and C

/*
 * 虽然说可以实现简单的大整数加减法，但还是麻烦。
 * 在64位整数范围内，考虑溢出情况进行判断即可。
 */


int main(){
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        long long int A,B,C,D;
        bool isBigger = false;
        cin >> A >> B >> C;
        D = A + B;
        if(A >= 0 && B >= 0 && D < 0)
            isBigger = true;
        else if(A < 0 && B < 0 && D >= 0)
            isBigger = false;
        else if(D > C)
            isBigger = true;
        cout << "Case #" << i;
        if(isBigger)
            cout << ": true" << endl;
        else
            cout << ": false" << endl;
    }
    return 0;
}
