#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 蓝桥杯练习 BASIC-27 2n皇后问题

// 循环宏
#define _for(i, a, b) for(int i = (a); i < b;i++)

// 整数读取
long long int readint() {
    long long int tmp;
    scanf("%lld", &tmp);
    return tmp;
}

int cnt = 0;

bool is_safe(vector<vector<int> > &pic, vector<int> pos, int row) {
    for (int i = 0; i < row; i++) {
        /* 如果：
         * 1. 某一非row行上的棋子(i,pos[i])与第row行的上的棋子(row,pos[row])在同一列
         * 2. 或在同一斜线上
         * 则冲突。
         */
        if (pos[i] == pos[row] || abs(i - row) == abs(pos[i] - pos[row]))
            return false;
    }
    return true;
}

void blackdfs(vector<vector<int> > &blackpic, vector<int> blackpos, const int &n, int blackrow) {
    // 当黑棋也递归到blackrow==n时，说明黑棋找到了可行的布局
    // 于是我们找到了一组可行的黑棋-白棋布局，计数加1
    if (blackrow == n) {
        cnt++;
        return;
    }
    // DFS主体
    for (blackpos[blackrow] = 0; blackpos[blackrow] < n; blackpos[blackrow]++) {
        // 只在可下棋&落子安全的位置进行进一步的DFS
        if (blackpic[blackrow][blackpos[blackrow]] == 1 && is_safe(blackpic, blackpos, blackrow)) {
            blackdfs(blackpic, blackpos, n, blackrow + 1);
        }
    }
}

void dfs(vector<vector<int> > &pic, vector<int> pos, const int &n, int row) {
    /* pic: 当前的地图，描述哪些位置可以下棋
     * pos： 当前组合上每一行棋子所在的列。亦即对0<=i<n,棋子的位置是(i,pos[i])
     * n: 棋盘尺寸
     * row: 当前递归考察的行位置，从0递归，直到row=n时白棋布局完成，再进行黑棋的DFS
     */
    // 当row==n时，找到了一种可行的白皇后布局，需要进一步找到可行的黑棋布局
    if (row == n) {
        // 新建一个图供布置黑棋使用
        vector<vector<int> > blackpic(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                blackpic[i][j] = pic[i][j];
            }
        }
        // 将白皇后的位置标为0，即不可下黑棋
        for (int i = 0; i < n; i++) {
            blackpic[i][pos[i]] = 0;
        }
        // 进行黑棋的DFS
        vector<int> blackpos(n);
        blackdfs(blackpic, blackpos, n, 0);
        return;
    }
    // 以下遍历棋盘上row行上所有格子，每个格子进行一次递归DFS搜索
    for (pos[row] = 0; pos[row] < n; pos[row]++) {
        // 只在可下棋&落子安全的位置进行进一步的DFS
        if (pic[row][pos[row]] == 1 && is_safe(pic, pos, row)) {
            dfs(pic, pos, n, row + 1);
        }
    }
}

int main() {
    int n = readint();
    vector<vector<int> > pic(n, vector<int>(n));
    vector<int> pos(n, 0);
    _for(i, 0, n) {
        _for(j, 0, n) {
            pic[i][j] = readint();
        }
    }
    dfs(pic, pos, n, 0);
    cout << cnt << endl;
    return 0;
}
