#include <iostream>
using namespace std;

//找和为K的两个元素
//在一个长度为n(n < 1000)的整数序列中，判断是否存在某两个元素之和为k。
//输入:第一行输入序列的长度n和k，用空格分开。第二行输入序列中的n个整数，用空格分开。
//输出:如果存在某两个元素的和为k，则输出yes，否则输出no。

int main() {
    int num[1000];
    int n,k;
    bool state = false;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> num[i];
    }
    for (int i = 0; i < n-1 ; i++){
        for (int j = n-1; j > i; j-- ){
            if (num[i] + num[j] == k){
                state = true;
                break;
            }
        }
        if (state) break;
    }
    if (!state){
        cout << "no" << endl;
    }
    else {
        cout << "yes" << endl;
    }
    return 0;
}
