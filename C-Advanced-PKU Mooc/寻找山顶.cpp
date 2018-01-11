#include <iostream>
using namespace std;

/**
 *  寻找山顶
 *
 *  描述
 *  在一个m×n的山地上，已知每个地块的平均高程，请求出所有山顶所在的地块
 *  (所谓山顶，就是其地块平均高程不比其上下左右相邻的四个地块每个地块的平均高程小的地方)。
 *
 *  输入
 *  第一行是两个整数，表示山地的长m（5≤m≤20）和宽n（5≤n≤20）。
 *  其后m行为一个m×n的整数矩阵，表示每个地块的平均高程。每行的整数间用一个空格分隔。
 *
 *  输出
 *  输出所有上顶所在地块的位置。每行一个。按先m值从小到大，再n值从小到大的顺序输出。
 *
*/
void input(int data[22][22],int m,int n){
    for(int i = 1;i < m + 1;i++){
        for(int j = 1;j < n + 1;j++){
            cin >> data[i][j];
        }
    }
}

bool judge(int data[22][22],int x,int y){
    if(data[x][y] >= data[x - 1][y] && data[x][y] >= data[x + 1][y] &&
               data[x][y] >= data[x][y - 1] && data[x][y] >= data[x][y + 1])
        return true;
    else
        return false;
}

void output(int data[22][22],int m,int n){
    for(int i = 1;i < m + 1;i++){
        for(int j = 1;j < n + 1;j++){
            if(judge(data,i,j)){
                cout << i - 1 << ' ' << j - 1 << endl;
            }
        }
    }
}

int main() {
    int m,n,height[22][22] = {0};
    cin >> m >> n;
    input(height,m,n);
    output(height,m,n);
    return 0;
}
