#include <iostream>
#include <queue>
using namespace std;

/**
 *  走出迷宫
 *
 *  描述
 *  当你站在一个迷宫里的时候，往往会被错综复杂的道路弄得失去方向感，如果你能得到迷宫地图，事情就会变得非常简单。
 *  假设你已经得到了一个n*m的迷宫的图纸，请你找出从起点到出口的最短路。
 *
 *  输入
 *  第一行是两个整数n和m(1 <= n,m <= 100)，表示迷宫的行数和列数。
 *  接下来n行，每行一个长为m的字符串，表示整个迷宫的布局。字符'.'表示空地，'#'表示墙，'S'表示起点,'T'表示出口。
 *
 *  输出
 *  输出从起点到出口最少需要走的步数。(你不能起出迷宫外)
 *
*/

//尝试BFS算法

struct zone{
    int x,y,dist;   //存储行、列、距起点步数
    char terr;
};

//用于四个方向搜索
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};


int main() {
    zone que[100*100],start;
    char labyrinth[100][100] = {'\0'};
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> labyrinth[i][j];
            if(labyrinth[i][j] == 'S'){
                start.x = i;
                start.y = j;
            }
        }
    }
    int checked[100][100] = {0};

    //加载起始节点到队列开头
    int front = -1,rear = -1;
    que[++rear].terr = labyrinth[start.x][start.y];
    que[rear].x = start.x;
    que[rear].y = start.y;
    que[rear].dist = 0;
    checked[start.x][start.y] = 1;

    while (front < rear){
        ++front;
        //抵达终点（出队列）
        if(que[front].terr == 'T'){
            cout << que[front].dist << endl;
            return 0;
        }
        //不是终点，就开始对上下左右四个节点进行搜索
        else{
            for (int i = 0; i < 4; ++i) {
                zone next;
                next.x = que[front].x + dx[i];
                next.y = que[front].y + dy[i];
                if(next.x >= 0 && next.x < n && next.y >=0 && next.y < m
                   && !checked[next.x][next.y] && labyrinth[next.x][next.y] != '#')
                {   //将符合条件的节点（边界内、未搜索、不是墙）加入队列，并标记搜索过的节点为checked
                    que[++rear].terr = labyrinth[next.x][next.y];
                    que[rear].x = next.x;
                    que[rear].y = next.y;
                    que[rear].dist = que[front].dist + 1;
                    checked[next.x][next.y] = 1;
                }
            }
        }
    }
    cout << "No way." << endl;
    return 0;
}
