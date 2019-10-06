#include <set>
#include <iostream>
#include <string>
using namespace std;

/*
 * PKU 程序设计与算法慕课（三） C++面向对象 期末考试
 * 016:编程填空：维护平面点
 *
 */

// 在此处补充你的代码
// 未完成
typedef pair<int,int> Plot;
class myComp{
public:
    bool operator () (const Plot p1,const Plot p2){
        if(p1.first != p2.first)
            return p1.first < p2.first;
        else
            return p1.second < p2.second;
    }
};
// 结束
int main() {
    string cmd;
    set<pair<int, int>, myComp> S;
    while (cin >> cmd) {
        if (cmd == "A") {
            int x, y;
            cin >> x >> y;
            S.insert(make_pair(x, y));
        } else if (cmd == "Qx") {
            int x;
            cin >> x;
            cout << S.lower_bound(make_pair(x, -1))->second << endl;
        } else if (cmd == "Qy") {
            int y;
            cin >> y;
            cout << S.lower_bound(make_pair(-1, y))->first << endl;
        } else {
            int x, y;
            cin >> x >> y;
            S.erase(make_pair(x, y));
        }
        int i;
    }
    return 0;
}