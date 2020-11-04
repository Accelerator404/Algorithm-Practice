#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// 蓝桥杯练习 ALGO-8 操作格子

// 循环宏
#define _for(i, a, b) for(int i = (a); i < b;i++)

// 整数读取
long long int readint() {
    long long int tmp;
    scanf("%lld", &tmp);
    return tmp;
}

// 线段树相关
struct node {
    // 该节点管理的数据范围（原数组上的区间）
    int l;
    int r;
    // 该节点管理区间的信息
    int maxvalue;   // max([l,r])
    int sum;        // sum([l,r])
};

class SegTree {
private:
    vector<node> data;
public:
    SegTree(int size) {
        data.resize(4 * size);
        init(1, size, 1);
    }

    void init(int left, int right, int i) {
        // 递归初始化线段树
        // 每次初始化子树的根节点data[i]，随后初始化其的两棵子树
        // 两棵子树各表示节点i代表的范围[l,r]的一半，且其在树中下标为2i,2+1（二叉树特性）
        data[i].l = left;
        data[i].r = right;
        data[i].maxvalue = 0;
        data[i].sum = 0;
        if (left != right) {
            int mid = (left + right) / 2;
            init(left, mid, 2 * i);
            init(mid + 1, right, 2 * i + 1);
        }
    }

    void insert(int i, int j, int value) {
        // 递归到叶节点，叶节点的信息（和、最大值）直接取相应格子的信息
        if (data[i].l == data[i].r) {
            data[i].maxvalue = value;
            data[i].sum = value;
            return;
        }
        // 不是叶节点，则左右子树分别下传
        int mid = (data[i].l + data[i].r) / 2;
        if (j <= mid)
            insert(2 * i, j, value);
        else
            insert(2 * i + 1, j, value);
        // 递归完毕，自下而上更新节点值
        data[i].maxvalue = max(data[2 * i].maxvalue, data[2 * i + 1].maxvalue);
        data[i].sum = data[2 * i].sum + data[2 * i + 1].sum;
    }

    int find_sum(int i, int x, int y) {
        // 递归求解
        if (x == data[i].l && y == data[i].r) {
            return data[i].sum;
        }
        int mid = (data[i].l + data[i].r) / 2;
        if (y <= mid)
            return find_sum(2 * i, x, y);
        else if (x > mid)
            return find_sum(2 * i + 1, x, y);
        else
            return find_sum(2 * i, x, mid) + find_sum(2 * i + 1, mid + 1, y);
    }

    int find_max(int i, int x, int y) {
        if (x == data[i].l && y == data[i].r) {
            return data[i].maxvalue;
        }
        int mid = (data[i].l + data[i].r) / 2;
        if (y <= mid)
            return find_max(2 * i, x, y);
        else if (x > mid)
            return find_max(2 * i + 1, x, y);
        else
            return max(find_max(2 * i, x, mid), find_max(2 * i + 1, mid + 1, y));
    }

};

int main() {
    int n, m;
    cin >> n >> m;
    // 初始化线段树，存入数据
    SegTree segTree(n);
    _for(i, 1, n + 1) {
        int tmp = readint();
        segTree.insert(1, i, tmp);
    }
    // 进行一系列操作
    _for(i, 1, m + 1) {
        int p, x, y;
        cin >> p >> x >> y;
        if (p == 1)
            segTree.insert(1, x, y); // 修改时从树根节点开始
        else if (p == 2)
            cout << segTree.find_sum(1, x, y) << endl;
        else if (p == 3)
            cout << segTree.find_max(1, x, y) << endl;
    }
    return 0;
}
