#include <iostream>

using namespace std;

//PAT Basic No.1006

int main() {
    int n;
    cin >> n;
    if(n > 99)
        for (int i = 0; i < n / 100; ++i)
            cout << 'B';
    if(n > 9)
        for (int j = 0; j < (n % 100) / 10; ++j)
            cout << 'S';
    if(n % 10 >0)
        for (int k = 1; k <= n % 10; ++k)
            cout << k;
    cout << endl;
    return 0;
}
