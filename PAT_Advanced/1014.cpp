#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//PAT Advanced 1014 Waiting in Line

/*
 * 应该注意，每一名顾客选择队列的时候并不知道这个队列其他人办理业务会花费的时间，只看队列长度选队，
 * 所以假设队列第一人办业务要9个小时，后面排队的M-1人就全部办不了业务了~
 * 在银行开门时，队伍前M*N名顾客会按窗口1~N顺序一排排地填满队列，之后才开始需要考虑每个队列的进出。
 */

struct waitingQueue{
    int qPopTime,qEndTime;
    queue<int> q;
};

string time_to_HHMM(int timeByMinutes){
    string hour = to_string(timeByMinutes/60);
    string minute = to_string(timeByMinutes%60);
    while (hour.length() < 2)
        hour = '0' + hour;
    while (minute.length() < 2)
        minute = '0' + minute;
    string res = hour + ":" + minute;
    return res;
}

int main() {
    int N, M, K, Q, index = 1;
    cin >> N >> M >> K >> Q;
    vector<int> time(K + 1), endTime(K + 1);
    for(int i = 1; i <= K; i++) {
        scanf("%d", &time[i]);
    }
    vector<waitingQueue> window(N + 1);
    vector<bool> sorry(K + 1, false);
    //按顺序填充初始队列
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            if(index <= K){
                window[j].q.push(time[index]);
                //判断队列前方办理完成时间是否超出17:00
                if(window[j].qEndTime >= (17-8) * 60)
                    sorry[index] = true;
                window[j].qEndTime += time[index];
                endTime[index] = window[j].qEndTime;
                window[j].qPopTime = window[j].q.front();
                index++;
            }
        }
    }
    while(index <= K) {
        int tempMinute = window[1].qPopTime, tempWindow = 1;
        for(int i = 2; i <= N; i++) {
            if(window[i].qPopTime < tempMinute) {
                tempWindow = i;
                tempMinute = window[i].qPopTime;
            }
        }
        window[tempWindow].q.pop();
        window[tempWindow].q.push(time[index]);
        window[tempWindow].qPopTime +=  window[tempWindow].q.front();
        if(window[tempWindow].qEndTime >= 540)
            sorry[index] = true;
        window[tempWindow].qEndTime += time[index];
        endTime[index] = window[tempWindow].qEndTime;
        index++;
    }
    for(int i = 1; i <= Q; i++) {
        int query, minute;
        scanf("%d", &query);
        minute = endTime[query];
        if(sorry[query] == true) {
            printf("Sorry\n");
        } else {
            cout<< time_to_HHMM(minute + 8 * 60) << endl;
        }
    }
    return 0;
}
