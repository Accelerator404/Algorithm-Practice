#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <iomanip>
using namespace std;

//PAT Advanced No.1065 “单身狗”


int main(){
    int N;
    cin>>N;
    //考虑0号客人，“不存在”记为-1
    vector<int> couple(100001,-1);
    for (int i = 0; i < N; ++i) {
        int A,B;
        cin >> A >> B;
        couple[A] = B;
        couple[B] = A;
    }
    int M;
    cin >> M;
    vector<int> guestList(100001,-1),arrival,soleman;

    for (int i = 0; i < M; ++i) {
        int g;
        cin >> g;
        guestList[g] = 1;
        arrival.push_back(g);
    }
    for (int i = 0; i < M; ++i) {
        if(couple[arrival[i]] == -1 || couple[arrival[i]]>-1 && guestList[couple[arrival[i]]] == -1){
            soleman.push_back(arrival[i]);
        }
    }
    sort(soleman.begin(),soleman.end());
    cout << soleman.size() << endl;
    bool first = true;
    //应当考虑没有单身客人的情况
    if(soleman.size() > 0){
        for (int i = 0; i < soleman.size(); ++i) {
            if(first)
                first = false;
            else
                cout << ' ';
            printf("%05d",soleman[i]);
        }
        cout << endl;
    }
    return 0;
}
