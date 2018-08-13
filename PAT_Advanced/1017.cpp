#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//PAT Advanced 1017 Queueing at Bank

/*
 * 这个就是队列的问题，可以认为所有顾客进入银行的时候立刻取号，这点与直接窗口前排队的1014题不同。
 * 但是不用queue也可以做。
 */

struct node{
    int hour,minute,second,arriveBySec;
    int P;
};

bool compare(node A,node B){
    if(A.hour != B.hour)
        return A.hour<B.hour;
    else if(A.minute != B.minute)
        return A.minute < B.minute;
    else
        return A.second < B.second;
}

int main() {
    int N,K;
    cin >> N >> K;
    vector<node> data;
    for (int i = 0; i < N; ++i) {
        node tmp;
        scanf("%d:%d:%d %d",&tmp.hour,&tmp.minute,&tmp.second,&tmp.P);
        tmp.arriveBySec = tmp.hour*60*60+tmp.minute*60+tmp.second;
        tmp.P *= 60;
        if(tmp.arriveBySec <= 17*60*60)
            data.push_back(tmp);
    }
    sort(data.begin(),data.end(),compare);
    if(data.size() == 0){
        cout << "0.0" << endl;
        return 0;
    }
    double average = 0.0;
    vector<int> window(K, 28800);
    for(int i = 0; i < data.size(); i++) {
        //找到最早空出的窗口
        int windowPtr = 0, minFinishTime = window[0];
        for(int j = 1; j < K; j++) {
            if(minFinishTime > window[j]) {
                minFinishTime = window[j];
                windowPtr = j;
            }
        }
        //不需要排队的顾客
        if(window[windowPtr] <= data[i].arriveBySec) {
            window[windowPtr] = data[i].arriveBySec + data[i].P;
        } 
        //需要排队的顾客
        else {
            average += (window[windowPtr] - data[i].arriveBySec);
            window[windowPtr] += data[i].P;
        }
    }
    printf("%.1f",average/60.0/data.size());
    return 0;
}
