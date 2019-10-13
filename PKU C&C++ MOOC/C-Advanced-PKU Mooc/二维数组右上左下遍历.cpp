#include <iostream>
using namespace std;

/**
二维数组右上左下遍历
给定一个row行col列的整数数组array，要求从array[0][0]元素开始，按从左上到右下的对角线顺序遍历整个数组。

输入：输入的第一行上有两个整数，依次为row和col。
余下有row行，每行包含col个整数，构成一个二维整数数组。
（注：输入的row和col保证0 < row < 100, 0 < col < 100）

输出：按遍历顺序输出每个整数。每个整数占一行。

*/

int main() {
    int row,col,p = 0,q = 0;
    cin >> row >> col;
    int array[100][100] = {0};
    //输入矩阵数据
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            cin >> array[i][j];
        }
    }
    //开始遍历
    while(true){
        cout << *(*(array + p) + q) << endl;
        //判断越界
        if(p + q >= row + col - 2) break;
        //从左边界向上边界遍历
        else if(q == 0 && p < col - 1){
            q = p + 1;
            p = 0;
        }
        //从左边界向右上边界遍历
        else if(q == 0 && p >= col - 1){
            p = p + q + 1 - (col - 1);
            q = col - 1;
        }
        //从下边界向上边界遍历
        else if(p == row - 1 && p + q < col -1){
            q = p + q + 1;
            p = 0;
        }
        //下边界向右下边界遍历
        else if(p == row - 1 && p + q >= col - 1){
            p = (p + q) + 1 - (col - 1);
            q = col - 1;
        }
        //对角线移动
        else{
            p++;
            q--;
        }
    }
    return 0;
}
