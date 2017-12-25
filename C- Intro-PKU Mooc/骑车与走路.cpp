#include <iostream>
using namespace std;
//骑车与走路
//在北大校园里,没有自行车,上课办事会很不方便.但实际上,并非去办任何事情都是骑车快.
//因为骑车总要找车、开锁、停车、锁车等,这要耽误一些时间.
//假设找到自行车,开锁并车上自行车的时间为27秒;停车锁车的时间为23秒;步行每秒行走1.2米,骑车每秒行走3.0米.
//请判断走不同的距离去办事,是骑车快还是走路快.
//输入第一行为待处理的数据的数量n,其后每一行整数为一次办事要行走的距离,单位为米.
//输出对应每个整数,如果骑车快,输出一行"Bike";如果走路快,输出一行"Walk";如果一样快,输出一行"All".

int main() {
    int n;
    cin >> n;
    double length[n],t1,t2;
    for (int i = 0 ; i < n; i++){
        cin >> length[i];
        t1 = 27 + 23 + length[i] / 3.0;
        t2 = length[i] / 1.2;
        if (t1 < t2)
            cout << "Bike" << endl;
        else if (t1 > t2)
            cout << "Walk" << endl;
        else if (t1 == t2)
            cout << "All" << endl;
    }
    return 0;
}
