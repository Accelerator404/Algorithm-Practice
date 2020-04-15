#include <iostream>
#include <vector>

using namespace std;

/*
 * 洛谷 P1003 铺地毯
 */
struct carpet {
    unsigned int i, a, b, g, k;
};

bool inCarpetArea(unsigned int x, unsigned int y, carpet c) {
    unsigned int xl = c.a;
    unsigned int xr = c.a + c.g;
    unsigned int yd = c.b;
    unsigned int yu = c.b + c.k;
    return xl <= x && x <= xr && yd <= y && y <= yu;
}

int main() {
    int n, x, y;
    int top;
    cin >> n;
    vector<carpet> info(n);
    for (int i = 0; i < n; ++i) {
        info[i].i = i + 1;    // 地毯编号
        scanf("%d%d%d%d", &info[i].a, &info[i].b, &info[i].g, &info[i].k);
    }
    cin >> x >> y;
    top = -1;
    // 倒序验证
    for (int j = n - 1; j >= 0; --j) {
        if (inCarpetArea(x, y, info[j])) {
            top = info[j].i;
            break;
        }
    }
    cout << top;
    return 0;
}