#include <iostream>
using namespace std;

//汉诺塔
//递归的应用

void move(int n,int a,int b,int c) {
    if(n == 1){
        cout << "把一个盘子从柱子" << a << "移到" << c << endl;
    }
    else if (n >= 2){
        move(n - 1,a,c,b);
        cout << "把一个盘子从柱子" << a << "移到" << c << endl;
        move(n - 1,b,a,c);
    }
    else
        cout << "error" << endl;
}

int main() {
    cout << "依次输入汉诺塔层数、初始柱子号、暂存柱子号、目标柱子号" << endl;
    int n,x,y,z;
    cin >> n >> x >> y >> z;
    move(n,x,y,z);
    return 0;
}
