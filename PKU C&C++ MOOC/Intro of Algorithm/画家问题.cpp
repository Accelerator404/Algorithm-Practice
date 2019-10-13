#include <iostream>
using namespace std;

/**
 * 画家问题
 * 描述
 * 有一个正方形的墙，由N*N个正方形的砖组成，其中一些砖是白色的，另外一些砖是黄色的。Bob是个画家，想把全部的砖都涂成黄色。
 * 但他的画笔不好使。当他用画笔涂画第(i, j)个位置的砖时， 位置(i-1, j)、 (i+1, j)、 (i, j-1)、 (i, j+1)上的砖都会改变颜色。
 * 请你帮助Bob计算出最少需要涂画多少块砖，才能使所有砖的颜色都变成黄色。
 *
 * 输入
 * 第一行是个整数t(1≤t ≤20)，表示要测试的案例数。然后是t个案例。每个案例的首行是一个整数n (1≤n ≤15)，表示墙的大小。
 * 接下来的n行表示墙的初始状态。每一行包含n个字符。第i行的第j个字符表示位于位置(i,j)上的砖的颜色。“w”表示白砖，“y”表示黄砖.
 *
 * 输出
 * 每个案例输出一行。如果Bob能够将所有的砖都涂成黄色，则输出最少需要涂画的砖数，否则输出“inf”。
 *
 */

class brick{
public:
    char color;
    int painted;
    brick():color('w'),painted(0){}
    brick(char c):color(c),painted(0){}
    void paint(){
        painted++;
        painted = painted % 2;
    }
    int paintStats(){
        return painted;
    }
    void resetPaint(){
        painted = 0;
    }
    int colorByInt(){
        if (color == 'y')
            return 1;
        else if (color == 'w')
            return 0;
    }
};

brick map0[16][17];
int leastPaintNum,n;
int guess(){
    int r,c;
    int paintNum = 0;
    for(r = 1;r < n;r++)
        for(c = 1; c < n + 1;c++){
            map0[r+1][c].resetPaint();
            //假如和为1，则需要在下方一点绘画（注意最后的额外“+1”）
            map0[r+1][c].painted = (map0[r][c].colorByInt() + map0[r][c].painted + map0[r-1][c].painted
                                 + map0[r][c-1].painted + map0[r][c+1].painted + 1) % 2;
            if(map0[r+1][c].painted == 1)
                paintNum++;
        }

        //判断最后一行是否全部黄色，不是则跳出
        for (c = 1; c < n + 1; c++)
            if ((map0[n][c-1].paintStats() + map0[n][c].paintStats() + map0[n][c+1].paintStats()
                 + map0[n-1][c].paintStats()) % 2 + map0[n][c].colorByInt() != 1)
                return -1;
    //统计第一行
    for (int c = 1; c < n + 1; ++c) {
        if(map0[1][c].painted == 1)
            paintNum++;
    }
    return paintNum;
}

void enumerate(){
    int c;
    for ( c = 1;c < n + 1; c++)
        map0[1][c].resetPaint();
    while (true){
        int paintNum = guess();
        //仅在最后一行符合条件的情况下，判断刷漆次数是否最少并记录最少值
        if(leastPaintNum < 0 && paintNum >= 0 || leastPaintNum > paintNum && paintNum >= 0)
            leastPaintNum = paintNum;
        ++map0[1][1].painted;
        c = 1;
        while (map0[1][c].painted > 1){
            map0[1][c].painted = 0;
            c++;
            map0[1][c].painted++;
            //map0[1][c].paintStats() == 1且未枚举到最后一列，则跳至while循环开头进行列的归零和“进位”
        }
        if(map0[1][n+1].painted != 0)
            break;
    }
}

void resetMatrix(){
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 17; ++j) {
            map0[i][j].color = 'w';
            map0[i][j].resetPaint();
        }

    }
}

int main() {
    int t;
    cin >> t;
    while(--t >= 0){
        cin >> n;
        resetMatrix();
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                char tmp;
                cin >> tmp;
                map0[i][j].color = tmp;
            }
        }
        leastPaintNum = -1;
        enumerate();
        if(leastPaintNum < 0)
            cout << "inf" << endl;
        else
            cout << leastPaintNum << endl;
    }
    return 0;
}
