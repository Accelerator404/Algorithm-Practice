#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

//PAT Basic No.1005 “继续(3n+1)猜想”

int Callatz(int k){
    if(k % 2 == 0)
        return k/2;
    else
        return (3*k + 1)/2;
}

bool compare(int i,int j){
    return j<i;
}

int main(){
    int K;
    vector<int> path,origin,important;
    cin >> K;
    while (--K >= 0){
        int N;
        cin >> N;
        origin.push_back(N);
        while (N != 1){
            N = Callatz(N);
            if(N != 1)
                path.push_back(N);
        }
    }
    //将输入数从大到小排序
    sort(origin.begin(),origin.end(),compare);
    int count = 0;
    for(auto it1 = origin.begin();it1 != origin.end();++it1){
    //find函数返回迭代器位置，置于最后一位（null）说明未找到目标
        auto it2 = std::find(path.begin(),path.end(),*it1);
        if(it2 == path.end()) {
            important.push_back(*it1);
        }
    }
    for(auto it1 = important.begin();it1 != important.end();++it1){
        if(it1 != important.end() - 1)
            cout << *it1 << ' ';
        else
            cout << *it1;
    }
    return 0;
}
