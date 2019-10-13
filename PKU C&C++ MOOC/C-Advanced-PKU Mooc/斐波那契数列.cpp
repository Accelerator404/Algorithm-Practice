#include <iostream>
using namespace std;

//斐波那契数列
//递归的应用

int fibonacci(int n){
    if(n == 0)
        return 1;
    else if(n == 1)
        return (0 + fibonacci(0));
    else if(n > 1)
        return ( fibonacci(n - 2)+ fibonacci(n - 1));
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        cout << fibonacci(i) << endl;
    }
    return 0;
}
