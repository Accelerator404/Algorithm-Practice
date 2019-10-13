#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//PAT Advanced Level 1029 Median

/*
 * 1.内存有限；
 * 2.两个序列都已排序。
 */

int main() {
    int N1,N2;
    vector<int> seq(200009);
    cin >> N1;
    for (int i = 1; i <= N1; ++i) {
        int tmp;
        scanf("%d",&tmp);
        seq[i] = tmp;
    }
    cin >> N2;
    //在数列N1后设一个最大int32，避免比较N2数列当前数与N1数列时超出N1数列范围
    seq[N1+1] = INT32_MAX;
    int count = 0,midPos = (N1+N2+1)/2,i = 1;
    //count从小到大开始数两个数列的数，数到midpos位置输出，i是对数列1的指针
    for (int j = 1; j <= N2; j++) {
        int temp;
        scanf("%d", &temp);
        //从小到大开始与N1数列进行比较
        while (seq[i] < temp) {
            //数N1次数
            count++;
            if (count == midPos) cout << seq[i];
            i++;
        }
        //数N2次数
        count++;
        if (count == midPos) cout << temp;
    }
    //数完N2还没有到midpos说明midpos在N1，继续数N1
    while (i <= N1) {
        count++;
        if (count == midPos) cout << seq[i];
        i++;
    }
    return 0;
}
