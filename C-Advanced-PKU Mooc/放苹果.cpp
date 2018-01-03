#include <iostream>
using namespace std;

//放苹果
//把n个同样的苹果放在m个同样的盘子里，问在允许空盘的情况下共有多少种不同的分法？
//如5，1，1和1，5，1是同一种分法。

int comb1(int n, int m){ //专门在无空盘子情况下进行统计
    int count = 0;
    if (m == 1)
        count = 1;
    else if (m == 2)
        count = n / 2;
    else if (m > 2){
        for (int i = n - m + 1; i > n / m;i--){
            count += comb1(n - i,m - 1);
        }
    }
    return count;
}

int comb(int n,int m) { //n为苹果，m为盘子数目，处理筛选空盘子情形
    int count = 0;
    if(m > n){
        count = comb(n,n);
    }
    else{
        for(int i = 1;i <= m;i++){
            count += comb1(n,i);
        }
    }
    return count;
}

int main() {
    int m,n;
    cin >> n >> m;
    cout << comb (n,m);
    return 0;
}
