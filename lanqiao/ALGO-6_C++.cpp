#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

// 蓝桥杯练习 ALGO-6 安慰奶牛

// 循环宏
#define _for(i, a, b) for(int i = (a); i < b;i++)

// 整数读取
long long int readint() {
    long long int tmp;
    scanf("%lld", &tmp);
    return tmp;
}

struct road {
    int p1;
    int p2;
};

// 超载比较运算符，使得该struct可以作为map的key
bool operator<(const road &r1, const road &r2) {
    if (r1.p1 < r2.p1 || (r1.p1 == r2.p1 && r1.p2 < r2.p2))
        return true;
    else
        return false;
}

vector<int> C;  // 交谈耗时
map<road, int> L; // 走路耗时
vector<road> originRoad;  // 原有道路

vector<int> Ranch;  // 加入到生成树中的点，一个并查集

set<road> selectedRoad; // 选择的边
map<road, int> newWeight; //

int calWeight(int p1, int p2) {
    road tmp;
    tmp.p1 = p1;
    tmp.p2 = p2;
    return L[tmp] * 2 + C[p1] + C[p2];
}

bool cmp(road &r1, road &r2) {
    return newWeight[r1] < newWeight[r2];
}

void init_disSet(vector<int> &s, int len) {
    // 从1开始的N个
    s.resize(len + 1);
    _for(i, 1, len + 1) {
        s[i] = i;
    }
}

int findDisSetRoot(int p, vector<int> &s) {
    // 带压缩路径
    int a = p;
    while (s[p] != p)
        p = s[p];
    while (a != s[a]) {
        int z = a;
        a = s[a];
        s[z] = p;
    }
    return p;
}

void union_disSet(int p1, int p2, vector<int> &s) {
    int r1 = findDisSetRoot(p1, s);
    int r2 = findDisSetRoot(p2, s);
    if (r1 != r2) {
        s[r2] = r1;
    }
}

int main() {
    int N, P;
    int sum = 0;
    int min_C = 1e9 + 1; // 起始点需要额外安慰一次，所以选择权值最小的节点过夜
    cin >> N >> P;
    C.resize(N + 1);
    _for(i, 1, N + 1) {
        C[i] = readint();
        min_C = min(C[i], min_C);
    }
    _for(i, 0, P) {
        road tmp;
        tmp.p1 = readint();
        tmp.p2 = readint();
        if (tmp.p1 > tmp.p2) {
            swap(tmp.p1, tmp.p2);
        }
        L[tmp] = readint();
        originRoad.push_back(tmp);
    }

    // 初始化节点并查集
    init_disSet(Ranch, N);
    // Kruskal算法
    // 计算真正的边权重
    for (vector<road>::iterator iter = originRoad.begin(); iter != originRoad.end(); ++iter) {
        newWeight[*iter] = calWeight(iter->p1, iter->p2);
    }
    // 将边按照权重升序排序
    sort(originRoad.begin(), originRoad.end(), cmp);
    // 迭代选择权重最小的边构成生成树
    for (vector<road>::iterator iter = originRoad.begin(); iter != originRoad.end(); ++iter) {
        // 取得该边两个顶点所在并查集的根
        int r1 = findDisSetRoot(iter->p1, Ranch);
        int r2 = findDisSetRoot(iter->p2, Ranch);
        // 如果两个顶点均在同一个连通分量中（并查集父节点一致），不加入该边
        if (r1 == r2)
            continue;
        else {
            // 加入该边（可以仅使用一个计数变量，以保证边数为N-1）
            selectedRoad.insert(*iter);
            // 合并
            union_disSet(r1, r2, Ranch);
            // 将该边的时间计入
            sum += newWeight[*iter];
            // 取足N-1条边后退出
            if (selectedRoad.size() == N - 1)
                break;
        }
    }
    cout << sum + min_C << endl;
    return 0;
}
