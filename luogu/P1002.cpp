#include <iostream>
#include <vector>

using namespace std;

/*
 * 洛谷 P1002 过河卒
 *
 * 这题是动态规划问题。
 */
typedef pair<int, int> p_coo;

bool isAcceptableAction(p_coo target_p, p_coo horse_p, p_coo B) {
    /*
     * 使用函数判断某一步是否可行
     */
    int m = B.first;
    int n = B.second;
    // 马封锁的坐标位置
    // 使用{}初始化vector需要c++11
    vector<int> fx = {0, -2, -1, 1, 2, 2, 1, -1, -2};
    vector<int> fy = {0, 1, 2, 2, 1, -1, -2, -2, -1};
    for (int i = 0; i < 9; ++i) {
        if (target_p.first == horse_p.first + fx[i] && target_p.second == horse_p.second + fy[i])
            return false;
    }
    return !(target_p.first > m || target_p.second > n);
}

int main() {
    p_coo p_horse, B;
    cin >> B.first >> B.second >> p_horse.first >> p_horse.second;
    // 出于方便，0行0列代表-1行-1列，所以所有坐标+1
    // f矩阵表示每个坐标上经过的路径数
    // 由于卒的行走规则是只能下、右，所以每个点能经过的路径是另外两个方向的值的和
    // 即动态规划，某个点的最优解是左上两个相邻点代表的子问题最优解之和
    unsigned long long int f[22][22] = {{0}};
    p_horse.first += 1;
    p_horse.second += 1;
    B.first += 1;
    B.second += 1;
    f[1][1] = 1;
    for (int i = 1; i <= B.first; ++i) {
        for (int j = 1; j <= B.second; ++j) {
            if (isAcceptableAction(p_coo(i, j), p_horse, B)) {
                // 此处的max用来避免f[1][1]一开始就被覆盖
                f[i][j] = max(f[i][j], f[i - 1][j] + f[i][j - 1]);
            }
        }
    }
    cout << f[B.first][B.second];
    return 0;
}