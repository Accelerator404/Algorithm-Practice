#include <iostream>

using namespace std;

/*
 * 第11届蓝桥杯 第二次模拟赛
 * 题7 螺旋矩阵
 */

int getPointLayer(int x, int y, int m, int n) {
    // 归一化
    if (x > (m + 1) / 2)
        x = m + 1 - x;
    if (y > (n + 1) / 2)
        y = n + 1 - y;
    int layer = x > y ? y : x;
    return layer;
}

int base(int layer, int m, int n) {
    if (layer == 1)
        return 0;
    int b = 0;
    for (int i = 1; i < layer; ++i) {
        int thisLayerM = m - (i - 1) * 2;
        int thisLayerN = n - (i - 1) * 2;
        if(thisLayerN >= 2)
            b += 2*thisLayerM + 2*(thisLayerN-2);
        else if (thisLayerN == 1)
            b += thisLayerM;
    }
    return b;
}

int genSpiralMat(int x, int y, int layer, int m, int n) {
    int cl = layer;
    int cr = m + 1 - layer;
    int ru = layer;
    int rd = n + 1 - layer;
    int base_ = base(layer,m,n);
    if (y == ru) {
        // 上缘
        return base_ + (x-cl + 1);
    }
    else if ( x == cr){
        return base_ + (m - 2 * (layer - 1)) + (y - ru);
    }
    else if (y == rd){
        int ba = genSpiralMat(cr,rd,layer,m,n);
        int d = m - x -layer + 1;
        return ba + d;
    }
    else if (x== cl){
        int ba = genSpiralMat(cl,rd,layer,m,n);
        int d = n - y -layer + 1;
        return ba + d;
    }
    return -1;
}

void test(int m, int n){
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <=m ; ++j) {
            cout << genSpiralMat(j, i, getPointLayer(j, i, m, n), m, n) << ' ';
        }
        cout << endl;
    }

}

int main() {
    int n, m;
    int r, c;
    cin >> n >> m;
    cin >> r >> c;
    cout << genSpiralMat(c, r, getPointLayer(c, r, m, n), m, n);
    return 0;
}