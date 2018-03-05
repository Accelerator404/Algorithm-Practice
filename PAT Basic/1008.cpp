#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//PAT Basic No.1008

/**
 * 循环移位可以使用三次反转算法，原理为前N-M位的数（假定位置i）移动到N-i位，再移动到(N-M-(N-i-M))+M位，即到M+i位
 */

int main() {
    int N,M;
    cin >> N >> M;
    if(M > N)
        M -= N;
    vector<int> array(N);
    for (int i = 0; i < N; ++i){
        int tmp;
        cin >> tmp;
        array[i] = tmp;
    }
    reverse(array.begin(),array.end());
    reverse(array.begin(),array.begin() + M);
    reverse(array.begin() + M,array.end());
    for (int j = 0; j < N; ++j) {
        if(j != 0)
            cout << " ";
        cout << array[j];
    }
    return 0;
}
