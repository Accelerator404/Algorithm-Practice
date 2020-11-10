#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 蓝桥杯练习 BASIC-18 矩形面积交

// 循环宏
#define _for(i, a, b) for(int i = (a); i < b;i++)

// 整数读取
long long int readint() {
    long long int tmp;
    scanf("%lld", &tmp);
    return tmp;
}

struct Point {
    double x;
    double y;
};

Point read_point() {
    Point p;
    cin >> p.x >> p.y;
    return p;
}

void swap_rect(Point &p1, Point &p2) {
    if (p1.x > p2.x)
        swap(p1.x, p2.x);
    if (p1.y > p2.y)
        swap(p1.y, p2.y);
}

bool cmpx(Point &p1, Point &p2) {
    return p1.x < p2.x;
}

bool cmpy(Point &p1, Point &p2) {
    return p1.y < p2.y;
}

int main() {
    Point p1 = read_point();
    Point p2 = read_point();
    Point p3 = read_point();
    Point p4 = read_point();
    // 保证每个矩形的顶点都是（左下、右上）这两个
    swap_rect(p1, p2);
    swap_rect(p3, p4);
    // 检查矩形是否重合
    if ((p1.x < p3.x && p2.x < p3.x) || (p1.y < p3.y && p2.y < p3.y) || (p3.x < p1.x && p4.x < p1.x) ||
        (p3.y < p1.y && p4.y < p1.y)) {
        cout << "0.00" << endl;
        return 0;
    }
    // 获取相重合范围的边长
    vector<Point> list = {p1, p2, p3, p4};
    sort(list.begin(), list.end(), cmpx);
    double x_diff = abs(list[2].x - list[1].x);
    sort(list.begin(), list.end(), cmpy);
    double y_diff = abs(list[2].y - list[1].y);
    // 计算面积
    double area = x_diff * y_diff;
    printf("%.02f", area);
    return 0;
}
