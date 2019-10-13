#include <iostream>
using namespace std;
//找出第k大的数
//用户输入N和K，然后接着输入N个正整数（无序的），程序在不对N个整数排序的情况下，找出第K大的数。
//注意，第K大的数意味着从大到小排在第K位的数。
//输入N、K、数组a[N]，输出b
int main() {
    //输入
    int N,K,b;
    cin >> N >> K;
    int num[K];
    for (int i=0;i<K;i++)
        num[i] = 0;

    for (int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        if (temp > num[0]) {
            for (int j = K - 1; j > 0; j--) {
                num[j] = num[j - 1];
            }
            num[0] = temp;
        }
        else if (temp > num[K-2] && temp < num[0]) {
            for (int j = 0; j < K - 2; j++) {
                if (temp < num[j] && temp > num[j+1]) {
                    for (int k = K - 1; k > j + 1; k--) {
                        num[k] = num[k-1];
                    }
                    num[j+1] = temp;
                }
            }
        }
        else if (temp > num[K-1] && temp < num[K-2]){
            num[K-1] = temp;
        }
    }

    cout << num[K-1] <<endl;
    return 0;
}
