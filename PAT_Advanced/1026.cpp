#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//PAT Advanced 1026 Table Tennis

struct customer{
    int arriveTime,servingTime,playingTime,waitingTime = 0;
    bool isVIP = false;
};

struct table{
    vector<customer> serviced;
    int endTime = 8*60*60,count;
    bool isVIPReserve = false;
};

bool compare1(customer A,customer B){
    return A.arriveTime < B.arriveTime;
}

bool compare2(customer A,customer B){
    return A.servingTime < B.servingTime;
}

int findNextVIP(int VIPID,const vector<customer> & waitQueue){
    VIPID++;
    while (VIPID < waitQueue.size() && !waitQueue[VIPID].isVIP){
        VIPID++;
    }
    return VIPID;
}

int main(){
    vector<customer> waitQueue;
    vector<table> tables;
    int N,K,M;
    cin >> N;
    waitQueue.resize(N);
    for (int i = 0; i < N; ++i) {
        int hh,mm,ss;
        scanf("%d:%d:%d %d %d",&hh,&mm,&ss,&waitQueue[i].playingTime,&waitQueue[i].isVIP);
        waitQueue[i].arriveTime = 60*hh + mm*60 + ss;
    }
    sort(waitQueue.begin(),waitQueue.end(),compare1);
    cin >> K >> M;
    tables.resize(K);
    for (int i = 0; i < M; ++i) {
        int u;
        cin >> u;
        tables[u].isVIPReserve = true;
    }
    //todo



    return 0;
}
