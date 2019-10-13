#include <iostream>
using namespace std;

/**
计算矩阵边缘元素之和
输入一个整数矩阵，计算位于矩阵边缘的元素之和。
所谓矩阵边缘的元素，就是第一行和最后一行的元素以及第一列和最后一列的元素。

输入：第一行为整数k，表示有k组数据。
每组数据有多行组成，表示一个矩阵：
第一行分别为矩阵的行数m和列数n（m < 100，n < 100），两者之间以空格分隔。
接下来输入的m行数据中，每行包含n个整数，整数之间以空格作为间隔。

输出：输出对应矩阵的边缘元素和，一个一行。

*/

int main() {
    int k,count = 0;
    cin >> k;
    int m,n;
    while(cin >> m >> n){
    //注意：coursera的oj应该对通过变量定义数组范围不能通过编译，把下一行的m、n都换成100即可通过
        int matrix[m][n] = {0},sum = 0;
        //输入矩阵数据
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                cin >> matrix[i][j];
                //输入同时判断与累加
                if(i == 0 || i == m - 1 || j == 0 || j == n - 1 ){
                    sum += matrix[i][j];
                }
            }
        }
        //输出和
        cout << sum << endl;
        //数据处理计数
        count++;
        if(count >= k) break;
    }
    return 0;
}
